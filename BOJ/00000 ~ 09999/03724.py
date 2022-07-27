T = int(input())
for t in range(0, T):
    M, N = map(int, input().split())
    arr = []
    for i in range(0, N):
        line = list(map(int, input().split()))
        arr.append(line)
    maxmul = 1
    maxidx = 0
    for i in range(0, N):
        maxmul *= arr[i][0]
    for j in range(1, M):
        mul = 1
        for i in range(0, N):
            mul *= arr[i][j]
        if mul >= maxmul:
            maxmul = mul
            maxidx = j
    print(maxidx + 1)