def func():
    message = input ("Enter the sentence that you want to check: ") 
    lowercount=0
    uppercount=0
    for char in message:
        if char.lower()==char:
            lowercount+=1
        elif char.upper()==char:
            uppercount +=1
    print(f"Number of uppercase: {uppercount} , number of lower case: {lowercount}")
func()