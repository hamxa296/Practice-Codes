L = []
num = input("Enter the digits: ")
for digit in num:
    L.append(int(digit))
L = set(L)
L = list(L)
print(f"Hi guys this is the list after removing all the repetiions: {L}")