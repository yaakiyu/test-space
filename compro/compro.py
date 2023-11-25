# competetive programming
# 競プロにつかえるもの

INTIN = lambda: int(input())
def MAPIN(kansu=int):
    return map(kansu, input().split())
LISTIN = lambda k=int: list(MAPIN(k))

import sys
sys.setrecursionlimit(1000000)
sys.set_int_max_str_digits(0)
input = lambda: sys.stdin.readline()[:-1]
# もしpypyなら
# import pypyjit; pypyjit.set_param('max_unroll_recursion=-1')

# UnionFindするとき
# from atcoder.dsu import DSU  # 使い方：uf=DSU(頂点数) ; uf.merge(u, v) ; uf.same(u, v) ; uf.leader(u) ; uf.size(u) ; uf.groups()

# SCCするとき
# from stcoder.scc import SCCGraph # 使い方：g=SCCGraph(頂点数) ; g.add_edge(u, v) ; scc=g.scc()