from collections import Counter

n = int(input())
slices = Counter()
for _ in range(n):
    s, l = input().split()
    l = int(l)
    slices[s] += l
slices['S'] += 5
slices['M'] += 7
slices['L'] += 11
print(slices['S'] // 6 + slices['M'] // 8 + slices['L'] // 12)