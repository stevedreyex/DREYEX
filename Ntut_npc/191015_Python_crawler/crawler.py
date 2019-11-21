import requests
from bs4 import BeautifulSoup as bs

url = "https://www.books.com.tw/web/sys_saletopb/books"
my_get = requests.get(url)
# print(my_get)
# print(my_get.txt)
my_html = bs(my_get.text, "html.parser")
# print(my_html)

books = my_html.find_all("li", "item")
# books.find()
for book in books:
    book_name = book.find("div", "type02_bd-a").find("a")
    try:
        print(book_name.text)
    except:
        print("unexpected")