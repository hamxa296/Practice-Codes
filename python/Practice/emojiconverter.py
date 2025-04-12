message = input("Enter your message: ")

##for word in words:
    #if word == ":)":
      #  word = "😊"
    #elif word == ":(":
        #word = "😔"
   # elif word == "cry":
        #word = "😭"
    #replacement +=   word + " "
#print (replacement)
def emoji_converter(message):
    words = message.split(' ')
    replacement =''
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
    return replacement
print(emoji_converter(message))