import base64
S=str(input()).encode('ascii')
print(str(base64.b64decode(S))[2:-1])
