# https://codeforces.com/problemset/problem/510/A
m, n = list(map(int, input().split()))
last = True
for i in range(m):
    if i % 2 == 0:
        print("#" * n)
    else:
        if last:
            print("." * (n-1) + "#")
        else:
            print("#" + "." * (n-1))
        last = not last