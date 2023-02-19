from sys import stdin, stdout
from collections import defaultdict

total = 0
line = stdin.readline().rstrip('\n')

n, m, q = line.split(" ")
n = int(n)

edges = defaultdict(list)

for i in range(n-1):
    line = stdin.readline().rstrip('\n')
    node1, node2 = line.split(" ")
    edges[node1].append(node2)
    edges[node2].append(node1)

array = []
for i in range(n):
    line = stdin.readline().rstrip('\n')
    array.append(int(line))



print(edges)
print(array)




# stdout.write(a)
# stdout.write('\n')