message = input("Enter your message: ")
words = message.split(' ')
replacement =''
##for word in words:
    #if word == ":)":
      #  word = "😊"
    #elif word == ":(":
        #word = "😔"
   # elif word == "cry":
        #word = "😭"
    #replacement +=   word + " "
#print (replacement)

emojis = {
    ":)" : "😊",
    ":(" : "😔",
    "cry" : "😭",
    "aww" : "😍"
}
for word in words:
    check = emojis.get(word.lower(), "!")
    if  check != "!":
        replacement += check
    else: replacement += word + " "
print (replacement)