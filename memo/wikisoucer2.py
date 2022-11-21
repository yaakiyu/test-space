# wikisource link formatter

with open("memo/test.txt", encoding="utf-8") as f:
    data = f.read()


new_source = data.splitlines()

for count, line in enumerate(new_source):
    if count < 7:
        continue
    if not line.startswith(("==明治", "==大正", "==昭和", "==平成", "==令和")):
        new_source[count] = ""
    if line.startswith("==令和"):
        break

new_source = [l for l in new_source if l != ""]

with open("memo/test.txt", "w", encoding="utf-8") as f:
    f.write("\n".join(new_source))
