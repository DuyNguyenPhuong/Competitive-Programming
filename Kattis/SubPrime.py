from sys import stdin, stdout
import math

line = stdin.readline().rstrip('\n')

l, h = line.split(" ")
h = int(h)
l = int(l)

num = stdin.readline().rstrip('\n')

primes = [2,3,5,7]
current = 8
# isPrime = True

while (len(primes) <= h):
    isPrime = True
    i = 0
    while i < len(primes) and primes[i] <= math.sqrt(current):
        if current% primes[i] == 0:
            isPrime = False
            break
        else:
            i+=1
    
            
    if isPrime == True:
        primes.append(current)
    current+=1
    
# print(primes)
cnt = 0

for i in range(l-1, h):
    string = str(primes[i])
    if num in string:
        cnt +=1
print(cnt)

