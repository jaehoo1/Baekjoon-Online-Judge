T = int(input())
for n in range(1, T + 1):
    N, X = map(int, input().split())
    print(f"Case {n}: {N % X}")