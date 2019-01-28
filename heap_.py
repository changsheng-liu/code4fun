import heapq
import random

l = []
for i in range(10):
    l.append(random.randrange(0,100,5))
print(l)
heapq.heapify(l)
print(l)
heapq.heappush(l, random.randrange(0,100,5))
print(l)
t = heapq.heappop(l)
print(l)
t = heapq.heappushpop(l, 110)
print(l)
t = heapq.heapreplace(l,-10)
print(t)
print(l)
print(heapq.nlargest(4, l))
print(heapq.nsmallest(4,l))
