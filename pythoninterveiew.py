#%%
# reverse string 
x = "abcde"
print(x[::-1])

#%%
# sort dictory by value
x = {"a":43, "b":12, "c":65, "d": 23}
sorted(x.items(), key=lambda x:x[1])

#%%
# alist of a sorted list
x = [1,2,3,4,5]
import random
random.shuffle(x)

#%%
list1 = [1,2,3]
list2 = [3,4,5]
set1 = set(list1)
set2 = set(list2)
print(set1 & set2)
print(set1 ^ set2)
print(set1 | set2)