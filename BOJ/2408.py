def check(arr):
    for i in range(len(arr)):
        if arr[i]=='*' or arr[i]=='/':
            return True
    return False

N=int(input())
num=[]
num.append(int(input()))
op=[]
for i in range(N-1):
    op.append(input())
    num.append(int(input()))
i=0
while check(op):
    if op[i]=='*' or op[i]=='/':
        first=num[i]
        second=num[i+1]
        if op[i]=='*':
            first*=second
        else:
            first//=second
        num[i]=first
        del num[i+1]
        del op[i]
        i-=1
        N-=1
    i+=1
i=0
while N>1:
    first=num[i]
    second=num[i+1]
    if op[i]=='+':
        first+=second
    else:
        first-=second
    num[i]=first
    del num[i+1]
    del op[i]
    N-=1
print(num[0])
