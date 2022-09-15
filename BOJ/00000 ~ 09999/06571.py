from bisect import bisect_left, bisect_right

fibo = [1, 2]
while True:
    num = fibo[len(fibo)-2] + fibo[len(fibo)-1]
    if num > 10**100:
        break
    fibo.append(num)
while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    print(bisect_right(fibo, b) - bisect_left(fibo, a))