#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# 42 C++ Modules  提出用ワンコマンド・デプロイ・スクリプト
# 使い方: ./submit.sh <モジュール番号> <リポジトリURL>
# 例   : ./submit.sh 2 git@vogsphere-v2.42tokyo.jp:intra/yourid/cpp-module-0N.git
# ------------------------------------------------------------------------------

set -euo pipefail

# --- 1. 引数チェック -----------------------------------------------------------
if [[ $# -ne 2 ]]; then
  echo "Usage: $(basename "$0") <module_number> <repository_url>" >&2
  exit 1
fi

MODULE="$1"
REPO_URL="$2"

[[ "$MODULE" =~ ^[0-9]+$ ]] \
  || { echo "Error: module_number must be numeric." >&2; exit 1; }

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MODULE_DIR="$ROOT_DIR/$MODULE"

[[ -d "$MODULE_DIR" ]] \
  || { echo "Error: directory '$MODULE_DIR' not found." >&2; exit 1; }

# --- 2. モジュールディレクトリへ移動 ------------------------------------------
pushd "$MODULE_DIR" >/dev/null

# --- 3. 空ディレクトリに .gitkeep を追加 (任意) -------------------------------
if [[ -x "$ROOT_DIR/fillEmptyDir.sh" ]]; then
  "$ROOT_DIR/fillEmptyDir.sh" .
fi

# --- 4. Git 初期化／リモート設定 ---------------------------------------------
if [[ ! -d .git ]]; then
  git init
fi

git checkout -B master               # 42 用に master 固定
if git remote | grep -qx origin; then
  git remote set-url origin "$REPO_URL"
else
  git remote add origin "$REPO_URL"
fi

# --- 5. .gitignore (初回のみ) --------------------------------------------------
if [[ ! -f .gitignore ]]; then
cp "$ROOT_DIR/.gitignore" .
fi

# --- 6. コミット & プッシュ ----------------------------------------------------
git add -A
if ! git diff --cached --quiet; then
  git commit -m "Initial commit for C++ Module ${MODULE}"
else
  echo "No changes to commit."
fi

git push -u origin master

popd >/dev/null
echo "✔ Module ${MODULE} pushed to ${REPO_URL}"
