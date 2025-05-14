n = int(input())
arr = list(map(int, input().split()))

ans = 0
total = sum(arr)
for i in range(n):
    total -= arr[i]
    ans += total * arr[i]
print(ans)