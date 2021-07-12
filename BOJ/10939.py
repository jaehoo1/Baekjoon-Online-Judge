import base64
S=str(input()).encode('ascii')
print(str(base64.b32decode(S))[2:-1])
