from sys import stdin, stdout
from collections import defaultdict
import math

line = stdin.readline().rstrip('\n')

n, div = line.split(" ")

line = stdin.readline().rstrip('\n')

n = int(n)

div = int(div)

a = []

a = line.split(" ")

dictR = defaultdict(int)

for i in range(n):
    a[i] = int(a[i])
    num = a[i]//div
    dictR[num] += 1

# print(dictR)
sum = 0
for value in dictR.values():
    sum += value * (value -1)//2

# Round to 3 decimal place
print("%.3f" % sum)

