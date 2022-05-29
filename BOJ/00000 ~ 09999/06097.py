N, P = map(int, input().split())
string = str(N**P)
temp=0
for i in string:
    temp+=1
    print(i, end='')
    if temp==70:
        print()
        temp=0
