n = int(input())
for _ in range(n):
    m = int(input())
    x = 0
    while 2 ** x < m:
        y = x
        while 2 ** x + 2 ** y <= m:
            if 2 ** x + 2 ** y == m:
                print(f"{x} {y}\n", end="")
            y += 1
        x += 1