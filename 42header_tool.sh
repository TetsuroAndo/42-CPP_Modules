#!/bin/bash

# 42header_tool.sh
# 42のヘッダーを削除または挿入するスクリプト
# 使用法: ./42header_tool.sh [オプション] [ディレクトリ]

# 色の定義
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# ヘルプ表示関数
show_help() {
    echo -e "${BLUE}42header_tool${NC}"
    echo "42のソースコードファイルのヘッダーを削除または挿入します。"
    echo ""
    echo "usage: $0 [option] [directory]"
    echo ""
    echo "option:"
    echo "  -r, --remove         ヘッダーを削除します"
    echo "  -a, --add            ヘッダーを追加します"
    echo "  -h, --help           このヘルプを表示します"
    echo "  -u, --username USER  ユーザー名を指定します（デフォルト: 環境変数USERから取得）"
    echo "  -e, --email EMAIL    メールアドレスを指定します（デフォルト: username@student.42tokyo.jp）"
    echo "  -c, --check          ヘッダーの存在を確認します"
    echo ""
    echo "optionが指定されていない場合は、ヘッダーの存在確認のみを行います。"
    echo ""
    echo "example:"
    echo "  $0 -a .              カレントディレクトリ内のすべてのファイルにヘッダーを追加"
    echo "  $0 -r ./src          ./srcディレクトリ内のすべてのファイルからヘッダーを削除"
    echo "  $0 -a -u johndoe .   指定したユーザー名でヘッダーを追加"
    echo "  $0 ./src            ./srcディレクトリ内のファイルのヘッダー存在を確認"
    echo ""
}

# デフォルト値
ACTION="check" # デフォルトはチェックモード
TARGET_DIR="."
TARGET_FILE=""
IS_FILE=0 # 0=ディレクトリ、1=ファイル
USERNAME="${USER}"
EMAIL=""

# 引数解析
while [[ $# -gt 0 ]]; do
    case $1 in
        -r|--remove)
            ACTION="remove"
            shift
            ;;
        -a|--add)
            ACTION="add"
            shift
            ;;
        -h|--help)
            show_help
            exit 0
            ;;
        -u|--username)
            USERNAME="$2"
            shift 2
            ;;
        -e|--email)
            EMAIL="$2"
            shift 2
            ;;
		-c|--check)
            ACTION="check"
            shift
            ;;
        *)
            if [[ -d "$1" ]]; then
                # ディレクトリの場合
                TARGET_DIR="$1"
                IS_FILE=0
            elif [[ -f "$1" ]]; then
                # ファイルの場合
                TARGET_FILE="$1"
                IS_FILE=1
            else
                echo -e "${RED}error: invalid argument or non-existent file/directory: $1${NC}"
                show_help
                exit 1
            fi
            shift
            ;;
    esac
done

# メールアドレスが指定されていない場合はデフォルト値を設定
if [[ -z "$EMAIL" ]]; then
    EMAIL="${USERNAME}@student.42tokyo.jp"
fi

# ヘッダーが存在するか確認する関数
check_header() {
    local file="$1"
    
    # ファイルの先頭13行を取得
    local header_lines=$(head -n 13 "$file" 2>/dev/null)
    
    # 42ヘッダーの特徴をチェック
    if echo "$header_lines" | grep -q "\* © \|By:\|Created:\|Updated:\|\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*"; then
        echo -e "${GREEN}header exists: $file${NC}"
        return 0
    else
        echo -e "${YELLOW}header not found: $file${NC}"
        return 1
    fi
}

# ヘッダーを削除する関数
remove_header() {
    local file="$1"
    local temp_file=$(mktemp)
    
    # check_header関数を使用してヘッダーの存在を確認
    if check_header "$file" > /dev/null; then
        # ヘッダー（13行）を削除
        tail -n +13 "$file" > "$temp_file"
        mv "$temp_file" "$file"
        echo -e "${GREEN}header removed: $file${NC}"
        return 0
    else
        echo -e "${YELLOW}header not found: $file${NC}"
        rm "$temp_file"
        return 1
    fi
}

# ヘッダーを追加する関数
add_header() {
    local file="$1"
    local filename=$(basename "$file")
    local temp_file=$(mktemp)
    local current_date=$(date "+%Y/%m/%d %H:%M:%S")
    
    # check_header関数を使用してヘッダーの存在を確認
    if check_header "$file" > /dev/null; then
        echo -e "${YELLOW}header already exists: $file${NC}"
        rm "$temp_file"
        return 1
    fi
    
    # フィールドの固定幅を設定 - 42ヘッダーの標準仕様に基づく
    local FILENAME_WIDTH=50  # ファイル名用の幅
    local AUTHOR_WIDTH=40    # 著者情報用の幅
    
    # ファイル名のパディングを計算
    local filename_len=${#filename}
    local padding_filename=""
    
    # ファイル名が長すぎる場合は切り詰める
    if [[ $filename_len -gt 40 ]]; then
        filename="${filename:0:40}"
        filename_len=40
    fi
    
    # ファイル名のパディングを生成
    # ファイル名の後に「:+:      :+:    :+:」が来るように調整
    local padding_len=$((50 - filename_len))
    for ((i=0; i<padding_len; i++)); do
        padding_filename="$padding_filename "
    done
    
    # ユーザー情報のパディングを計算
    local user_email="$USERNAME <$EMAIL>"
    local user_email_len=${#user_email}
    local padding_user=""
    
    # ユーザー情報のパディングを生成
    # ユーザー情報の後に「+#+  +:+       +#+」が来るように調整
    local padding_user_len=$((40 - user_email_len))
    if [[ $padding_user_len -lt 1 ]]; then
        padding_user_len=1  # 最低で1つの空白を確保
    fi
    
    for ((i=0; i<padding_user_len; i++)); do
        padding_user="$padding_user "
    done
    
    # Created/Updated行のパディングを計算
    local created_padding=""
    local updated_padding=""
    
    # Created行のパディングを生成
    for ((i=0; i<12; i++)); do
        created_padding="$created_padding "
    done
    
    # Updated行のパディングを生成
    for ((i=0; i<11; i++)); do
        updated_padding="$updated_padding "
    done
    
    # ヘッダーを作成
    cat > "$temp_file" << EOF
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${filename}${padding_filename}:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ${USERNAME} <${EMAIL}>${padding_user}+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${current_date}${created_padding}by ${USERNAME}           #+#    #+#             */
/*   Updated: ${current_date}${updated_padding}by ${USERNAME}          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
EOF

    # ファイルの内容をヘッダーの後に追加
    cat "$file" >> "$temp_file"
    mv "$temp_file" "$file"
    echo -e "${GREEN}header added: $file${NC}"
    return 0
}

# ファイル名を適切にパディングする関数
pad_filename() {
    local filename="$1"
    local max_length=42
    local filename_length=${#filename}
    
    # ファイル名が長すぎる場合は切り詰める
    if (( filename_length > max_length )); then
        echo "${filename:0:max_length}"
        return
    fi
    
    echo "$filename"
}

# 対象ファイルを検索して処理
process_files() {
    local target="$1"
    local action="$2"
    local is_file="$3"
    local count_success=0
    local count_skipped=0
    local count_total=0
    local count_with_header=0
    local count_without_header=0
    local files=
    
    if [[ "$is_file" -eq 1 ]]; then
        # 単一ファイルの場合
        files="$target"
    else
        # ディレクトリの場合、C/C++ソースファイルとヘッダーファイルを検索
        files=$(find "$target" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \))
    fi
    
    # 各ファイルを処理
    while IFS= read -r file; do
        # ファイルが空でない場合のみ処理
        if [[ -n "$file" ]]; then
            count_total=$((count_total + 1))
            
            if [[ "$action" == "remove" ]]; then
                if remove_header "$file"; then
                    count_success=$((count_success + 1))
                else
                    count_skipped=$((count_skipped + 1))
                fi
            elif [[ "$action" == "add" ]]; then
                if add_header "$file"; then
                    count_success=$((count_success + 1))
                else
                    count_skipped=$((count_skipped + 1))
                fi
            elif [[ "$action" == "check" ]]; then
                if check_header "$file"; then
                    count_with_header=$((count_with_header + 1))
                else
                    count_without_header=$((count_without_header + 1))
                fi
            fi
        fi
    done <<< "$files"
    
    echo ""
    echo -e "${BLUE}process completed:${NC}"
    echo "  processed files: $count_total"
    
    if [[ "$action" == "check" ]]; then
        echo "  files with header: $count_with_header"
        echo "  files without header: $count_without_header"
    else
        echo "  success: $count_success"
        echo "  skipped: $count_skipped"
    fi
}

# メイン処理
echo -e "${BLUE}42header_tool${NC}"

if [[ "$IS_FILE" -eq 1 ]]; then
    echo "file: $TARGET_FILE"
else
    echo "directory: $TARGET_DIR"
fi

echo "username: $USERNAME"
echo "email: $EMAIL"
echo "action: $ACTION"
echo ""

# 処理実行
if [[ "$IS_FILE" -eq 1 ]]; then
    process_files "$TARGET_FILE" "$ACTION" "$IS_FILE"
else
    process_files "$TARGET_DIR" "$ACTION" "$IS_FILE"
fi

exit 0
