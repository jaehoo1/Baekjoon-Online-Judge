A = input()
B = input()
res = 0

dp = [[0] * len(B) for _ in range(len(A))]

for i in range(len(A)):
    for j in range(len(B)):
        if A[i] == B[j]:
            if i == 0 or j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1] + 1
        else:
            temp = 0
            if i > 0:
                temp = max(dp[i-1][j], temp)
            if j > 0:
                temp = max(dp[i][j-1], temp)
            dp[i][j] = temp
        if dp[i][j] > res:
            res = dp[i][j]

print(res)
