# wikisource形式変換システム

import re


with open("wikisource.txt") as f:
    # 法律原文を読み込み
    source = f.read()

starting_member = """{{header
 | title = {{PAGENAME}}
 | year = 
 | defaultsort = 
 | notes = 
< [[Wikisource:日本の法律]]

''''''（''''''）
*
*公布:
[[カテゴリ:の法律|]]
}}""".splitlines()

x = input("法令成立年(西暦)?")
starting_member[2] += x
starting_member[10] = "[[カテゴリ:の法律|]]"
x2 = input("法令名(ひらがな)?")
starting_member[3] += x2
starting_member[7] = f"'''''' ('''{x2}''')"



flags = [
    False,  # 目次始まったかどうか
    False,  # 目次終わったかどうか
]

for count, line in enumerate(source.splitlines()):
    if line == "目次" and not flags[0]:
        flags[0] = True
        source[count] = "\n== 目次 =="
    if flags[0] and not flags[1]:
        # 目次の途中
