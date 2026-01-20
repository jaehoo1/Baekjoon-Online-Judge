import math

d, h = map(float, input().split())
r = d / 2 + 5
print(math.pi * r * r + 2 * math.pi * r * h)