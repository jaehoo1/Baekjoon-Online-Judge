n, d = map(int, input().split())
solved = []
for i in range(n):
    solved.append(int(input()))
for i in range(n):
    print(d // sum(solved) * solved[i])