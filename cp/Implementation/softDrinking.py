n, k, l, c, d, p, nl, np = list(map(int, input().split()))
print(min((k * l) // nl, (c * d), p // np) // n)