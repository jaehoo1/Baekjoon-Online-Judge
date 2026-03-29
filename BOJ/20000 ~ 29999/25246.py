VOWELS = ['a', 'e', 'i', 'o', 'u']

s = input()

for i in range(len(s) - 1, -1, -1):
    if s[i] in VOWELS:
        result = s[:i+1] + "ntry"
        break

print(result)