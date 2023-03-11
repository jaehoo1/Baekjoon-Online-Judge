def ispalindrom(string) -> bool:
    if string == string[::-1]:
        return True
    else:
        return False
    
string = input()
for i in range(1, len(string)):
    if ispalindrom(string[:i]) and ispalindrom(string[i:]):
        print(string[:i], string[i:])
        exit()
print("NO")