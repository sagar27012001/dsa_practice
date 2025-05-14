def power(base, mul):
    if mul == 1:
        return base
    half = power(base, mul // 2)
    if mul % 2 == 1:
        return base * half * half
    else:
        return half * half

base, mul = map(int, input().split())
print(power(base, mul))