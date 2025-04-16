# https://codeforces.com/problemset/problem/144/A
n = int(input())
solders = list(map(int, input().split()))

maxi = mini = -1
for ind in range(n):
    if maxi == -1 or solders[ind] > solders[maxi]:
        maxi = ind
    if mini == -1 or solders[ind] <= solders[mini]:
        mini = ind

if maxi > mini:
    swaps = maxi + (n - 1 - mini) - 1
else:
    swaps = maxi + (n - 1 - mini)

print(swaps)
