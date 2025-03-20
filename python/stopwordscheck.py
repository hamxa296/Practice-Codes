message = input("Please enter your paragraph: ")
P_removed = ""
stopwords = [
    "the", "a", "an", "is", "are", "it", "that", "this", "these", "those",
    "i", "you", "he", "she", "we", "they", "me", "him", "her", "us", "them",
    "my", "your", "his", "her", "our", "their", "mine", "yours", "hers", "ours", "theirs",
    "and", "but", "or", "nor", "for", "so", "yet", "as", "while", "since", "because",
    "in", "on", "at", "by", "with", "about", "against", "through", "during", "before", "after",
    "to", "from", "of", "at", "into", "throughout", "among", "between", "over", "under",
    "have", "has", "had", "do", "does", "did", "will", "would", "can", "could", "should", "may", "might", "must",
    "be", "being", "been", "am", "is", "are", "was", "were",
    "not", "no", "nor", "neither", "never", "always", "sometimes", "often", "usually", "generally",
    "more", "less", "many", "few", "some", "all", "most", "every", "each", "both", "several",
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "said", "says", "saying", "told", "tells", "telling",
    "go", "goes", "going", "went", "gone",
    "get", "gets", "getting", "got", "gotten",
    "make", "makes", "making", "made",
    "know", "knows", "knowing", "knew", "known",
    "think", "thinks", "thinking", "thought",
    "take", "takes", "taking", "took", "taken",
    "see", "sees", "seeing", "saw", "seen",
    "come", "comes", "coming", "came", "come",
    "want", "wants", "wanting", "wanted",
    "look", "looks", "looking", "looked",
    "use", "uses", "using", "used",
    "find", "finds", "finding", "found",
    "tell", "tells", "telling", "told",
    "ask", "asks", "asking", "asked",
    "i'm", "you're", "he's", "she's", "it's", "we're", "they're",
    "i've", "you've", "we've", "they've",
    "i'd", "you'd", "he'd", "she'd", "we'd", "they'd",
    "i'll", "you'll", "he'll", "she'll", "we'll", "they'll"
]

for char in message:
    if char.isalpha() or char.isspace():
        P_removed += char
print(P_removed)
stopwords_list=[]
S_removed=""
P_removed.lower()
P_removed_list=[]
P_removed_list = P_removed.split(" ")
print (P_removed_list)
P_removed.split(" ")
counter = len(P_removed_list)
for i in range(counter):
    if P_removed_list[i] in stopwords:
        stopwords_list.append(P_removed_list[i])
    else: S_removed+=P_removed_list[i] + " "
print(stopwords_list)
P_removed_set = set(P_removed_list)
P_removed_set = list(P_removed_list)
counter2 = len(P_removed_set)
for i in range (counter2-1):
    count = P_removed_list.count(P_removed_set[i])
    print (f"{P_removed_set[i] } repeats {count} times!")
print(S_removed)
S_removed = S_removed.split(" ")
stopwords_list.count(stopwords_list[i])
stopwords_list= set(stopwords_list)
stopwords_list=list(stopwords_list)
print (stopwords_list)