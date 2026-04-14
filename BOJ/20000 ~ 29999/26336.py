import math

t = int(input())
for _ in range(t):
    miles, gas, food = map(int, input().split())
    print(miles, gas, food)
    miles -= 1
    print(miles // gas + miles // food - miles // math.lcm(gas, food))