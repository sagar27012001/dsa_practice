n = int(input())
mpp = {}
for i in range(n):

    num = int(input())
    cnt = 0
    base = 1
    ans = []
    while num:
        rem = num % 10
        if rem != 0:
            ans.append(base * rem)
            cnt += 1
        base *= 10
        num //= 10
    mpp[i] = [cnt, ' '.join(map(str, ans))]

for val in mpp.values():
    print(val[0])
    print(val[1])
