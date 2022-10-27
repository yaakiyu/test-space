# wikisource link formatter

with open("memo/test.txt", encoding="utf-8") as f:
    data = f.read()


new_source = data.splitlines()

for count, line in enumerate(new_source):
    if (
        line.startswith("||") and new_source[count - 2].startswith("|!")
        and new_source[count - 1][2:].startswith(
            ("明治", "大正", "昭和", "平成", "令和")
        ) and new_source[count - 3] == "|-" and "[[" not in line
        and count > 2000
    ):
        new_source[count] = f"||[[{line[2:]}]]"

with open("memo/test.txt", "w", encoding="utf-8") as f:
    f.write("\n".join(new_source))
