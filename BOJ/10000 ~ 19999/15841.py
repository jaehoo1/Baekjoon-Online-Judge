dp = [0, 1, 1]
for i in range(3, 491):
    dp.append(dp[i-1] + dp[i-2])
while True:
    num = int(input())
    if num == -1:
        break
    print("Hour %d: %d cow(s) affected" % (num, dp[num]))
