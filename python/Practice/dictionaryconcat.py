def func(*dicts):
    new = {}
    for d in dicts:
        for key in d:
            new[key]=d[key]
    print (new)
dict1 = {2:3,3:4}
dict2 = {5:6,7:8}
func(dict1, dict2)