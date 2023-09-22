# 高速優先度付きキューの実装(安全性は保証されない。)
from collections import deque

class heapq:
    def __init__(self, obj, /, *, sort: bool = True, key=None):
        if sort:
            obj = sorted(obj, key=key)
        self.queue = deque(obj)
        
