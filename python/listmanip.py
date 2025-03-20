L1=[1,2,3,4,5,6]
new =[]
for i in range (5):
    List = list(map(lambda y,x:y**x,[L1[i+1]],[L1[i]]))
    new.extend(List)
print (new)


