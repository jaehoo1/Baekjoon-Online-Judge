n, k = map(int, input().split())
d, s = map(int, input().split())
res = (d * n - k * s) / (n - k)
print("impossible" if res > 100 or res < 0 else res)