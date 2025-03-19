answer = ""
final = ""
message = input("Enter the sentence: " )
answer = message.split("-")
for word in answer:
    final +=word + " "
print (message)
print(final)