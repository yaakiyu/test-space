# wikisource link formatter

with open("test.txt", encoding="utf-8") as f:
    data = f.read()

data = "\n".join(data.splitlines()[2050:])

with open("test.txt", "w", encoding="utf-8") as f:
    f.write(data)
