op = ('*', '+', '-', '/')
optree = [''] * 3
dict = {}

def calculate():
    string = "4"
    for i in range(3):
        string += optree[i] + "4"
    return eval(string.replace("/", "//"))

def recur(depth):
    if depth == 3:
        string = "4 "
        for i in range(3):
            string += optree[i] + " 4 "
        dict[calculate()] = string.strip()
        return

    for i in range(4):
        optree[depth] = op[i]
        recur(depth + 1)

recur(0)
m = int(input())
for _ in range(m):
    n = int(input())
    if n in dict:
        print(dict[n], "=", n)
    else:
        print("no solution")