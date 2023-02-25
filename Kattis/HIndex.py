from sys import stdin, stdout
from collections import defaultdict
import math

line = stdin.readline().rstrip('\n')

num = int(line)

arr = []

for i in range(num):
    line = stdin.readline().rstrip('\n')
    arr.append(int(line))

arr.sort(reverse = True)

Hindex = 0

for i in range(num):
    if arr[i] >= i+1:
        Hindex = i+1
    else:
        break

print(Hindex)


