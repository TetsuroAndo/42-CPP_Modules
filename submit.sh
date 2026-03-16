#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# C++ Module Auto-Submit for 42 (temporary nested-git edition)
# Usage : ./submit.sh <MODULE_NUM> <REPO_URL>
# Example: ./submit.sh 2 git@vogsphere-v2.42tokyo.jp:intra/login/cpp-module-02.git
# ------------------------------------------------------------------------------

set -euo pipefail

# 引数チェック
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

# 空ディレクトリに .gitkeep を配置 (optional)
# [[ -x "$ROOT_DIR/fillEmptyDir.sh" ]] && "$ROOT_DIR/fillEmptyDir.sh" "$MODULE_DIR"

# モジュールディレクトリに移動
pushd "$MODULE_DIR" >/dev/null

# make test 実行
echo "Running tests..."
for exdir in ex*; do
  if [ -d "$exdir" ] && [ -f "$exdir/Makefile" ]; then
    echo "Testing $exdir..."
    if ! make -C "$exdir" test; then
      echo "Error: Tests failed in $exdir. Aborting submission." >&2
      popd >/dev/null
      exit 1
    fi
  fi
done

# ex* ディレクトリだけを一時リポジトリにコピーして push
TMPDIR=$(mktemp -d)
trap 'rm -rf "$TMPDIR"' EXIT

for exdir in ex*; do
  [ -d "$exdir" ] && cp -r "$exdir" "$TMPDIR/"
done

git -C "$TMPDIR" init -b master
git -C "$TMPDIR" add -A
git -C "$TMPDIR" commit -m "Submit CPP Module $MODULE"
git -C "$TMPDIR" push -f "$REPO_URL" master

popd >/dev/null
echo "✔ Module ${MODULE} successfully pushed to ${REPO_URL}"
