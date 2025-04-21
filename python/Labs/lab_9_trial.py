import requests
from bs4 import BeautifulSoup

url = "https://books.toscrape.com/"

# Send a request to fetch the webpage
response = requests.get(url)

# Check if the request was successful
if response.status_code == 200:
    # Parse the HTML content using BeautifulSoup
    soup = BeautifulSoup(response.text, "html.parser")

    # Find all book containers
    books = soup.find_all("article", class_="product_pod")

    # Loop through each book and extract title and price
    for book in books:
        title = book.h3.a["title"]  # Extract book title
        price = book.find("p", class_="price_color").text  # Extract book price
        print(f"Title: {title}, Price: {price}")

else:
    print("Failed to retrieve the website!")