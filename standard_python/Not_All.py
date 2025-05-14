from collections import Counter

n, m = map(int, input().split())
arr = list(map(int, input().split()))
flag = True
cnt = Counter(arr)
for i in range(1, m+1):
  if cnt[i] == 0:
    print(0)
    flag = False

if flag:
  ans = 0
  for k, v in cnt.items():
    ans += v - 1

  print(ans)