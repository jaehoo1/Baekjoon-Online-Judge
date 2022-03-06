P, K = map(int, input().split())
for i in range(2, K):
    if P % i == 0:
        print("BAD", i)
        exit()
print("GOOD")
