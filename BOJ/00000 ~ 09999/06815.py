a = int(input())
b = int(input())
count = 0
i = 1
while True:
    cur = i ** 6
    if cur > b:
        break
    i += 1
    if cur >= a:
        count += 1
print(count)