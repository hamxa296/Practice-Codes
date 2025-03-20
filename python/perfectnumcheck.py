def func(num):
    sum_check = 0
    for i in range (1,num):
        if num%i==0:
            sum_check+=i
    if sum_check == num:
        print("Number entered is PERFECT! :)")
    elif sum_check != num:
        print("number entered is not perfect! ")
num = int(input("Enter the number you want to check: " ))
func (num)