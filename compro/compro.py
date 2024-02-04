# competetive programming
# 競プロにつかえるもの

# sys関連
import sys
sys.setrecursionlimit(100000000)
sys.set_int_max_str_digits(10000000)
input = lambda: sys.stdin.readline()[:-1]
# もしpypyなら
#import pypyjit; pypyjit.set_param('max_unroll_recursion=-1')  # 再帰関数の展開をする
#from atcoder.dsu import DSU  # UnionFind　使い方：uf=DSU(頂点数) ; uf.merge(u, v) ; uf.same(u, v) ; uf.leader(u) ; uf.size(u) ; uf.groups()
#from stcoder.scc import SCCGraph # SCC 使い方：g=SCCGraph(頂点数) ; g.add_edge(u, v) ; scc=g.scc()
#from collections import deque  # Queue 使い方：q=deque(lis) ; q.popleft(item) ; q.append(item)
#from collections import Counter # Counter
#import heapq # Priority Queue 使い方：q=[...] ; heapq.heapify(q) ; heapq.heappush(q, item) ; heapq.heappop(q, item)
#from itertools import accumulate # 累積和
#from bisect import bisect_left, bisect_right # 二分探索
#from decimal import Decimal, getcontext; getcontext().prec = 100 # 正確な少数

INTIN = lambda: int(input())
def MAPIN(kansu=int):
    return map(kansu, input().split())
LISTIN = lambda k=int: list(MAPIN(k))



