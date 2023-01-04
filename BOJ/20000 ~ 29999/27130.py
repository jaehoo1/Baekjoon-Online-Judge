A = int(input())
B = str(input())
print(A)
print(B)
for i in range(len(B) - 1, -1, -1):
    print(A * int(B[i]))
print(A * int(B))