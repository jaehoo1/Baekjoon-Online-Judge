A, B, C = map(int, input().split())
T = int(input())
fee = 0

T -= 30
fee += A
if T < 0:
    T = 0
if T % B != 0:
    fee += C
fee += T // B * C

print (fee)