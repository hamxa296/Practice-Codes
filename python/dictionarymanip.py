from functools import reduce
employees = [
 {
 'fname':'Ali',
 'lname':'Khan',
 'age' : 33,
 'grade':'skilled'
 },
 {
 'fname':'Raja',
 'lname':'Atif',
 'age' : 34,
'grade':'semi-skilled'
},
{
        'fname':'John',
        'lname':'Carter',
        'age' : 35,
        'grade':'highly-skilled'
},
{
        'fname':'Yoyo',
        'lname':'Meo',
        'age' : 30,
        'grade':'skilled'
},
{
        'fname':'Ayesha',
        'lname':'Khan',
        'age' : 37,
        'grade':'highly-skilled'
}
]
def func(List,employees):
    
    if dict["grade"]=="highly-skilled":
        List.append(dict.get("fname") + dict.get("lname"))
    return List
print (list(reduce(func,employees)))