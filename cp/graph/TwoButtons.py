# https://codeforces.com/problemset/problem/520/B
from collections import deque

def get_minimum_steps(n, m):
    visited = set()
    que = deque([(n, 0)])
    while que:
        num, steps = que.popleft()
        if num == m:
            return steps
        
        if num * 2 <= 2 * m and num * 2 not in visited:
            que.append((num * 2, steps + 1))
            visited.add(num * 2)
        if num - 1 > 0 and num - 1 not in visited:
            que.append((num - 1, steps + 1))
            visited.add(num - 1)


n, m = list(map(int, input().split()))

print(get_minimum_steps(n, m))