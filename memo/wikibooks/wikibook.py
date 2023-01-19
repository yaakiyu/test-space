# wikibook formatter

import re

with open("memo/wikibooks/wikibook.txt") as f:
    data = f.read()

seiki_hyougen = r"([^a-zA-Z" # アルファベット以外にマッチ
seiki_hyougen += r"\u3040-\u309F\u30A0-\u30FF\uFF61-\uFF9F]" # ひらがなやカタカナ以外にマッチ
seiki_hyougen += r"+)" # 繰り返し
seiki_hyougen += r"（([\u3040-\u309F]+)）" # かっこのなか

# re.sub(seiki_hyougen, r"{{Ruby|\1|\2}}", data)

with open("memo/wikibooks/wikibook.txt", mode="w") as f:
    f.write(data)
