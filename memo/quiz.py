# クイズデータ自動変換システム

import csv

with open("memo/quiz.csv") as f:
    m = [i for i in csv.reader(f)]

obj = []

for line in m:
    if not isinstance(line[0], int):
        continue
    obj.append({"question": line[1], "answer": line[2]})

with open("memo/quiz.txt", mode="w") as f:
    f.write(str(obj))
