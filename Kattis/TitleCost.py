from sys import stdin, stdout
import math

line = stdin.readline().rstrip('\n')

title, cap = line.split(" ")

leng = len(title)

cap = float(cap)

if leng < cap:
    print(leng)
else:
    print(cap)
