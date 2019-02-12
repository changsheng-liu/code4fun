
#%%
#list and tuple
t = (1,2)
t = (1,)

x = list()
x = ["a", "b", "c"]
for s in range(len(x)):
    print(s)
    print(x[s])
x[-1]
x.append("d")
x.insert(1, "e")
del x[0]
print(x)
x.pop() #last 
x.pop(1)
print(x)
x.count("b")
x.extend(["1","2"]) # return original list x, not x + y return a new list
print(x)
x.remove("e")
x.reverse()
x.sort()

#%%
# list like related operations
x = [1]
y = [2]
x * 2
z = x+y
# slicing
x = [1,2,3,4,5,6]
x[0:2] #[0,2)
x[:2]
x[:-1]
x[-1:]
x[-2:-1] #[-2:-1)
x[:] # copy
x[1:5:2]
x[5:1:-2]
7 in x

#%% 
#list comprehensions
list(range(1,11))
list(x * x for x in range(1,11))
list(x for x in range(1,11) if x % 2 == 0)
list(x+y for x in range(1,3) for y in range(7,15))
L = {"X": "A", "Y":"B"}
[k+"="+v for k,v in L.items()]

#%%
#list generator --> not comprehension, create one by one

#%%
# generator


#%%
# iterat / iterator


#%%
#string related 


#%%
#dict
d = {1: "x", 2: "y", 3:"z"}
m = dict(n = "name", a = 12)
len(d)
d[1]
del d[2]
2 in d # HIGHLIGHT : key in dict
d[2] = "y"
d
m.clear()
m = d.copy() # shallow copy
m
{}.fromkeys([1,2])
m.get(4)
m.get(4,"N/A")
m.items()
m.items() is list # false for python 3
list(m.items()) is list # false for python 3
m.pop(1)
m.popitem()
d.setdefault(4,"N/A")
print(m)
print(d)
m[3] = "m"
m[5] = "t"
d.update(m)
print(d)
d.values() is list

#%%
#set 
l = [1,2,3,1]
s = set(l)
s.add(5)
s.remove(5)
s2 = set([2,3,8])
s | s2
s & s2

#%% 
#loop, condition
x = [1,2]
y = [1,2]
x is y
x == y
a, b, c = 1, 2, 3 
a, b, c = c, a, b # sequence unpacking
a = 1 if b == 2 else 3
assert a == 3
for i in x:
    print(i)
d = {1:"a",2:"b"}
for k in d:
    print(k)
for k, v in d.items():
    print("%d+%s"%(k,v))
y.append(5)
for t1,t2 in zip(x,y):
    print(t1)
    print(t2)
for idx, n in enumerate(x):
    print(n)
    print(idx)
sorted(x)
reversed(y)
for n in range(1,19):
    print(n)
else:
    print(-n)

#%%
# basic function and operations 


#%%
#high-level functions
def f(x):
    return x*x
r = map(f, [1,2,3,4,5,6])
list(r)

from functools import reduce

#%%
# OO Programing


#%% 
# Handle error


#%%
#IO

#%% 
#multi threading

#%% 
#basic methods
