N = int(input())
A = int(input())
B = int(input())

count = 0
for i in range(1, N + 1):
    if (i % A == 0 and i % B != 0) or (i % A != 0 and i % B == 0):
        count += 1
print(count)