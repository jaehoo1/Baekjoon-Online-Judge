def power(A, B, C):
    A %= C
    if B==1:
        return A
    elif B==0:
        return 1
    if B%2==1:
        return (A*power((A*A)%C, B//2, C))%C
    else:
        return power((A*A)%C, B//2, C)%C

A, B, C = map(int, input().split())
print(power(A, B, C))
