import math
while True:
    try:
        N = int(input())
        string = str(math.factorial(N))
        length = len(string)
        length -= 1
        while string[length]=='0':
            length -= 1
        print("%5d -> %c" % (N, string[length]))
    except EOFError:
        break
