burgers = []
beverages = []
for _ in range(3):
    burgers.append(int(input()))
for _ in range(2):
    beverages.append(int(input()))
print(min(burgers) + min(beverages) - 50)