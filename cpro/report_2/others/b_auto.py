# 問題2のプログラムを異なるNで回してどのような結果になるかを自動でデータ収集する
import subprocess

with open('output.txt', 'a') as output_file:
    for i in range(10000):
        n = 100 + i * 100
        result = subprocess.run(
            ['./a.out'],
            input=f'{n}\n',
            text=True,
            capture_output=True,
        )
        output_file.write(result.stdout)
