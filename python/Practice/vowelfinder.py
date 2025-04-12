def func(a):
    return a.lower()=="a"or a.lower()=="e" or a.lower()=="i"or a.lower()=="u"or a.lower()=="o" 
message = input("Enter string: ")
L = list(message)
print(list(filter(func,L)))
