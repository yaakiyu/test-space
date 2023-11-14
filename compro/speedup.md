# Faster Python X
dcだと「!」から始まる行がすべてコマンドライン実行になるので、それを利用してatcoderのコードテスト上で実験を行った。

## 内包表記とmapの比較(文字列結合)
```
python3 -m timeit "'-'.join(str(n) for n in range(1000))"
python3 -m timeit "'-'.join([str(n) for n in range(1000)])"
python3 -m timeit "'-'.join(map(str, range(1000)))"
```
### 出力
```
5000 loops, best of 5: 94.8 usec per loop
5000 loops, best of 5: 79.5 usec per loop
5000 loops, best of 5: 63.8 usec per loop
```
### 結論
mapが一番早い。あとなぜか、そのままjoinに渡すよりリストに一旦変換したほうが早い。

## listとtupleの比較(インスタンス化)
```
python3 -m timeit "list(range(100))"
python3 -m timeit "tuple(range(100))"
python3 -m timeit "list(range(1000))"
python3 -m timeit "tuple(range(1000))"
```
### 出力
```
500000 loops, best of 5: 499 nsec per loop
500000 loops, best of 5: 516 nsec per loop
50000 loops, best of 5: 8.1 usec per loop
50000 loops, best of 5: 7.69 usec per loop
```
### 結論
あんまり変わらない。
