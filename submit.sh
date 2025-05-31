#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# C++ Module Auto-Submit for 42 (temporary nested-git edition)
# Usage : ./submit.sh <MODULE_NUM> <REPO_URL>
# Example: ./submit.sh 2 git@vogsphere-v2.42tokyo.jp:intra/login/cpp-module-02.git
# ------------------------------------------------------------------------------

set -euo pipefail

# 1. 引数チェック
if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <module_number> <repository_url>" >&2
  exit 1
fi
MODULE="$1"
REPO_URL="$2"
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MODULE_DIR="$ROOT_DIR/$MODULE"

[[ "$MODULE" =~ ^[0-9]+$ ]] \
  || { echo "Error: module_num must be numeric." >&2; exit 1; }
[[ -d "$MODULE_DIR" ]] \
  || { echo "Error: directory '$MODULE_DIR' not found." >&2; exit 1; }

# 2. 空ディレクトリに .gitkeep を配置（任意）
# [[ -x "$ROOT_DIR/fillEmptyDir.sh" ]] && "$ROOT_DIR/fillEmptyDir.sh" "$MODULE_DIR"

# 3. 一時的 Git 初期化
pushd "$MODULE_DIR" >/dev/null
TEMP_GIT_CREATED=false
if [[ ! -d .git ]]; then
  git init -q
  TEMP_GIT_CREATED=true
fi

# 4. リモート origin 設定
if git remote | grep -qx origin; then
  git remote set-url origin "$REPO_URL"
else
  git remote add origin "$REPO_URL"
fi
git checkout -B master -q

# 5. .gitignore (初回のみ)
if [[ ! -f .gitignore ]]; then
cp "$ROOT_DIR/.gitignore" .
GITIGNORE_CREATED=true
fi

# 6. コミット & プッシュ
git add -A
if git diff --cached --quiet; then
  echo "No changes to commit."
else
  git commit -m "Auto-submit C++ Module ${MODULE}" -q
fi

# ブランチ履歴が無い場合は --force が不要／既にある場合は FF が通る限り通常 push
# もし履歴が繋がらず push が失敗した場合に限り --force-with-lease を再試行
if ! git push -u origin master; then
  echo "Non-fast-forward, retrying with --force-with-lease..."
  git push -u origin master --force-with-lease
fi

# 7. 後始末: 一時的に作った .git / .gitignore を掃除
if $TEMP_GIT_CREATED; then
  rm -rf .git
  echo "Temporary .git removed."
fi
if $GITIGNORE_CREATED; then
  rm -f .gitignore
  echo "Temporary .gitignore removed."
fi

popd >/dev/null
echo "✔ Module ${MODULE} successfully pushed to ${REPO_URL}"
