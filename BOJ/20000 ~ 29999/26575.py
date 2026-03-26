n = int(input())
for _ in range(n):
    d, f, p = map(float, input().split())
    print(f"${d * f * p:.2f}")