doors = [-1]
is_valid = True
N = int(input())
doors.append(int(input()))
for i in range(2, N + 1):
    next = 0 if doors[i - 1] else 1
    if (i > 2 and i % 2 == 0 and next != doors[2]) or (i > 3 and i % 3 == 0 and next != doors[3]):
        is_valid = False
        break
    doors.append(next)
print("\n".join(map(str, doors[2:])) if is_valid else "Love is open door")