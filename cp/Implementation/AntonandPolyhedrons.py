# https://codeforces.com/problemset/problem/785/A
n = int(input())

ans = 0
while n:
    polyhedron = input()
    if polyhedron == "Icosahedron":
        ans += 20
    elif polyhedron == "Cube":
        ans += 6
    elif polyhedron == "Octahedron":
        ans += 8
    elif polyhedron == "Dodecahedron":
        ans += 12
    else:
        ans += 4
    n -= 1

print(ans)
