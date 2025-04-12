from functools import reduce 
def func(a,b):
    return a+b
L = [[1,2,3],[4,5],[6,7]]
print (list(reduce(func,L)))