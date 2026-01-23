import math

w, h = map(int, input().split())
r = int(input())

print(w * h - r * r * math.pi / 4)