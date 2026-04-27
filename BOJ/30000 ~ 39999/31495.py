S = input()
print(S[1:-1] if S[0] == '\"' and S[-1] == '\"' and len(S) > 2 else "CE")