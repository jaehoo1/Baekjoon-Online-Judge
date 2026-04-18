dir = 0
for _ in range(10):
    t = int(input())
    if t == 1:
        dir += 1
    elif t == 2:
        dir += 2
    elif t == 3:
        dir -= 1
    if dir < 0:
        dir += 4
    elif dir >= 4:
        dir -= 4
print("NESW"[dir])