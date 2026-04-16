def function(N: int, S: str) -> str:
    return S[N:] + S

Z = int(input())
for _ in range(Z):
    N, C, S = input().split()
    N = int(N)
    C = int(C)
    for _ in range(C):
        S = function(N, S)
    print(S)