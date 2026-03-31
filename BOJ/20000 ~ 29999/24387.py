from operator import mul

honey_prices = sorted(map(int, input().split()))
buckets = sorted(map(int, input().split()))
print(sum(map(mul, honey_prices, buckets)))