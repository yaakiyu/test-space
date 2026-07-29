# c.cとc_fastest.cの出力があっているか調べる
import subprocess

res = []
print("Start calculating a.out...")

for i in range(1000):
    n = 10 + i * 10
    result = subprocess.run(
        ['./a.out'],
        input=f'{n}\n',
        text=True,
        capture_output=True,
    )
    res.append(result.stdout)

print("Start Checking b.out...")

for i in range(1000):
    n = 10 + i * 10
    result = subprocess.run(
        ['./b.out'],
        input=f'{n}\n',
        text=True,
        capture_output=True,
    )
    if res[i] != result.stdout:
        print(f"Error! {n}")
        break
else:
    print("All Ok!")
