# memo - 正規表現, re

import re

def main():
    "reモジュールのテスト用関数(テキトー)。"
    # 正規表現の参考↓
    # https://murashun.jp/article/programming/regular-expression.html
    # reモジュールの参考↓
    # https://note.nkmk.me/python-re-match-search-findall-etc/
    text = "huge  :    hoge"
    match = re.search(r" *: *", text)  # 空白に挟まれたコロンの検出。
    if not match:
        raise ValueError("見つからなかった。。。")
    left, right = text[:match.start()], text[match.end():]
    left_count, right_count = len(match[:match.find(":")]), len(match[match.find(":"):])
    return left, right, left_count, right_count
