N = int(input())
P = int(input())
price = P
if N >= 5:
    price = min(price, P - 500)
if N >= 10:
    price = min(price, int(P * 0.9))
if N >= 15:
    price = min(price, P - 2000)
if N >= 20:
    price = min(price, int(P * 0.75))
if price < 0:
    price = 0
print(price)