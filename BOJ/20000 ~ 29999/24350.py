def fact(n):
    ret = 1
    for i in range(1, n+1):
        ret *= i
    return ret

N, K = map(int, input().split())
cou = 0
string = str(fact(N)//fact(K)//fact(N-K))
for c in string:
    if c == '0':
        cou += 1
print(cou)