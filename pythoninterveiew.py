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
