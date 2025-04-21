import requests
from bs4 import BeautifulSoup
import pandas as pd
import matplotlib.pyplot as plt
import re

url = "http://books.toscrape.com/"
response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

books = soup.find_all("article", class_="product_pod")
book_data = []

for book in books:
    title = book.h3.a["title"]

    raw_price = book.find("p", class_="price_color").text
    price = float(re.sub(r"[^\d.]", "", raw_price))  

    rating_class = book.find("p", class_="star-rating")["class"][1]
    rating_dict = {"One": 1, "Two": 2, "Three": 3, "Four": 4, "Five": 5}
    numeric_rating = rating_dict.get(rating_class, 0)

    book_data.append({
        "Title": title.strip(),
        "Price": price,
        "Rating": numeric_rating
    })

df = pd.DataFrame(book_data)

df["Title"] = df["Title"].str.strip()
df["Price"] = df["Price"].round(2)


most_common_title = df["Title"].value_counts().idxmax()

avg_price = df["Price"].mean()

missing_data = df.isnull().sum()

plt.figure(figsize=(6,4))
df["Rating"].value_counts().sort_index().plot(kind="bar", color="salmon", edgecolor="black")
plt.title("Distribution of Star Ratings")
plt.xlabel("Star Rating")
plt.ylabel("Number of Books")
plt.grid(True)
plt.tight_layout()
plt.show()

print("Most frequent book title:", most_common_title)
print("Average book price: £", round(avg_price, 2))
print("\nMissing data:\n", missing_data)
