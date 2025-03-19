Ph_no = input ("Please enter your phone number: ")
digits = {
    0 : "zero",
    1 : "one",
    2 : "two",
    3 : "three",
    4 : "four",
    5 : "five",
    6 : "six",
    7 : "seven",
    8 : "eight",
    9 : "nine"
}
output = ""
for digit in Ph_no:
    #print (digits[int(digit)],"!")
    #print (digits.get(int(digit),"!"))
    output += digits.get(int(digit),"!") + " "
print (output)
