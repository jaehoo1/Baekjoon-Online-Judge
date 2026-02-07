n = int(input())
bits = 1
while n > 2 ** bits - 1:
    bits *= 2
print(f'{bits} {"bit" if bits == 1 else "bits"}')