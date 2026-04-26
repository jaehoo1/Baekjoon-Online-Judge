N = int(input())
D, P = 0, 0
for _ in range(N):
    winner = input()
    if winner == 'D':
        D += 1
    elif winner == 'P':
        P += 1
    if abs(D - P) >= 2:
        break
print(f"{D}:{P}")