# wikisource形式変換システム

from kanjize import kanji2int


with open("memo/wikisource.txt", encoding="utf-8") as f:
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

"""
made_year = 2000  # 法令成立年(西暦)
starting_member[2] += made_year
made_month = 1  # 法令成立月
made_day = 1  # 法令成立日
_date_string = f"{made_year}-{made_month}-{made_day}"

def year_converter_to_wareki(date_obj):
    gengo_data = {
        date(2019, 05, 01): {"name": "令和"},
        date(1989, 01, 08): {"name": "平成"},
        date(1926, 12, 25): {"name": "昭和"},
        date(1912, 07, 30): {"name": "大正"},
        date(1868, 01, 25): {"name": "明治"},
    }

    year, month, day = None, None, None

    #-で分けてリスト化
    obj_list = date_obj.split("-")
    #2桁や1桁のときは20**または19**にする
    if len(obj_list[0]) == 1:
        obj_list[0] = "200" + obj_list[0]
    elif len(obj_list[0]) == 2:
        obj_list[0] = ("19" if int(obj_list[0]) > 25 else "20") + obj_list[0]

    #年のみの入力は1月1日となる
    if len(obj_list) == 1:
        year = int(obj_list[0])
    #年月の場合は1日となる
    elif len(obj_list) == 2:
        year, month = tuple(obj_list)
        year, month = int(year), int(month)
    elif len(obj_list) == 3:
        year, month, day = tuple(obj_list)
        year, month, day = int(year), int(month), int(day)
    input_obj = date(year, month or 1, day or 1)

    #出てきた年を格納する
    result_year = ""

    #年を格納
    for key, value in gengo_data.items():
        if input_obj >= key:
            nen: int | str = input_obj.year - key.year + 1
            if nen == 1:
                nen = "元"
            result_year = f"{value['name']}{nen}年"
            break
    else:
        raise KeyError("古すぎて計算できませんでした。")

    #output（年月日を合算）
    result = ""

    #年のみの入力の場合は年のみで返す
    if not month:
        result = result_year
    else:
        #年月の場合
        if not day:
            result = f"{result_year}{month}月"
        #年月日の場合
        else:
            result = f"{result_year}{month}月{day}日"
    return result

nenn = year_converter_to_wareki(_date_string).split("年")[0]

x4 = input("法令名(ひらがな)?")
starting_member[3] += x4
starting_member[10] = f"[[カテゴリ:{nenn}年の法律|{x4}]]"
starting_member[7] = f"'''''' ('''{x4}''')"
"""

flags = [
    False,  # 目次始まったかどうか
    False,  # 目次終わったかどうか
    0,  # 章
    0,  # 節
    0,  # 条
    False,  # 附則に入ったかどうか
    0,  # 附則カウント
]

new_source = source.splitlines()[19:]

for count, line in enumerate(new_source):
    if line == "目次" and not flags[0]:
        flags[0] = True
        new_source[count] = "\n== 目次 =="
        continue
    if line == "" and flags[0] and not flags[1]:
        # 目次終了
        flags[1] = True
        continue
    if flags[0] and not flags[1]:
        # 目次の途中
        line = line.replace("―", " - ")
        if line.split("　")[0].endswith("節"):
            new_source[count] = f"::[[#{line.split('（')[0]}|{line}]]"
        else:
            new_source[count] = f":[[#{line.split('（')[0]}|{line}]]"
        continue

    splitted = line.split("　")[0]

    if flags[1] and not flags[5] and line.startswith("第") and splitted.endswith("章"):
        # 章の開始
        flags[2] = kanji2int(splitted[1:-1])
        new_source[count] = f"\n== {line} =="
        continue

    elif flags[1] and not flags[5] and line.startswith("第") and splitted.endswith("節"):
        # 節の開始
        flags[3] = kanji2int(splitted[1:-1])
        new_source[count] = f"\n=== {line} ==="
        continue

    elif flags[1] and not flags[5] and line.startswith("第") and splitted.endswith('条'):
        # 条の開始
        flags[4] = kanji2int(splitted[1:-1])
        if new_source[count - 1].startswith("（") and new_source[count - 1].endswith("）"):
            # 条の前の説明がある場合。
            new_source[count - 1
                ] = f'\n<span id="a{flags[4]}">{new_source[count - 1]}</span><br>'
            new_source[count] = f"'''{splitted}'''{line[len(splitted):]}"
        else:
            new_source[count] = f'\n<b id="a{flags[4]}">{splitted}</b>{line[len(splitted):]}'
        continue

    elif flags[1] and not flags[5] and line.startswith("第") and line.split("の")[0].endswith('条'):
        # 条の枝の開始
        _komakai = kanji2int(line.split("の")[1].split("　")[0])
        flags[4] = kanji2int(line.split("の")[0][1:-1])
        if new_source[count - 1].startswith("（") and new_source[count - 1].endswith("）"):
            # 条の前の説明がある場合。
            new_source[count - 1
                ] = f'\n<span id="a{flags[4]}.{_komakai}">{new_source[count - 1]}</span><br>'
            new_source[count] = f"'''{splitted}'''{line[len(splitted):]}"
        else:
            new_source[count] = f'\n<b id="a{flags[4]}.{_komakai}">{splitted}</b>{line[len(splitted):]}'
        continue

    elif flags[1] and not flags[5] and line.startswith("附　則"):
        # 附則スタート
        flags[5] = True
        flags[6] = 1
        new_source[count] = f"\n== {line} =="
        continue

    elif flags[5] and line.startswith("附　則　（"):
        # 新たな附則
        flags[6] += 1
        flags[4] = ""
        new_source[count] = f"\n=== {line} ==="

    elif flags[5] and line.startswith("第") and splitted.endswith('条'):
        # 附則内の条開始
        flags[4] = kanji2int(splitted[1:-1])
        if new_source[count - 1].startswith("（") and new_source[count - 1].endswith("）"):
            # 条の前の説明がある場合。
            new_source[count - 1
                ] = f'\n<span id="{flags[6] if flags[6] != 1 else ""}f{flags[4]}">\
{new_source[count - 1]}</span><br>'
            new_source[count] = f"'''{splitted}'''{line[len(splitted):]}"
        else:
            new_source[count
                ] = f'\n<b id="{flags[6] if flags[6] != 1 else ""}\
f{flags[4]}">{splitted}</b>{line[len(splitted):]}'

    elif line.startswith(("１", "２", "３", "４", "５", "６", "７", "８", "９")):
        # 項の開始
        if flags[5]:
            new_source[count] = f':<span id="{flags[6]}f{flags[4]}_{int(splitted[0])}">\
{int(splitted[0])}</span>　{"".join(line.split("　")[1:])}'
        else:
            new_source[count] = f':<span id="a{flags[4]}_{int(splitted[0])}">\
{int(splitted[0])}</span>　{"".join(line.split("　")[1:])}'

    elif line.startswith(("一", "二", "三", "四", "五", "六", "七", "八", "九", "十")):
        # 選択肢みたいなのの開始
        new_source[count] = f"::{line}"
    
    elif line.startswith((
        "イ　", "ロ　", "ハ　", "ニ　", "ホ　", "ヘ　", "ト　", "チ　", "リ　",
        "ヌ　", "ル　", "ヲ　", "ワ　", "カ　", "ヨ　", "タ　", "レ　", "ソ",
    )):
        # イロハ開始
        new_source[count] = f":::{line}"


new_source.append("{{PD-JapanGov}}")
new_source.append("")

source = "\n".join(source.splitlines()[:19] + new_source)

with open("memo/wikisource.txt", encoding="utf-8", mode="w") as f:
    f.write(source)
