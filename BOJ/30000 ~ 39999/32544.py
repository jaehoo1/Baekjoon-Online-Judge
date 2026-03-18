n = int(input())
layer = 0
while True:
    if layer + 1 > n:
        break
    layer += 1
    n -= layer
print(layer)