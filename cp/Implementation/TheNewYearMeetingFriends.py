ip = list(map(int, input().split()))
ip.sort()
print((ip[1] - ip[0]) + (ip[2] - ip[1]))