N = int(input())
s = input()
count = 0
for i in range(N):
    if (i < N - 1 and s[i] == 'a' and s[i + 1] == 'a') or (i > 0 and s[i] == 'a' and s[i - 1] == 'a'):
        count += 1
print(count)