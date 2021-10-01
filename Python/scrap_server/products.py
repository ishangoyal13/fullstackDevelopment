import json
import os
import pickle
import smtplib
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

from colorama import init, Fore
from selenium import webdriver

init()


chrome_options = webdriver.ChromeOptions()
chrome_options.binary_location = os.environ.get("GOOGLE_CHROME_BIN")
chrome_options.add_argument("--headless")
chrome_options.add_argument("--disable-dev-shm-usage")
chrome_options.add_argument("--no-sandbox")


class Products:
    def __init__(self, filename, email, product):
        self.products = {}
        self.filename = filename
        self.email = email
        self.product = product
        self.modules = list()
        self.server = smtplib.SMTP('smtp.gmail.com', 587)
        self.server.starttls()
        self.server.login("idiotpyscripts@gmail.com", "wwjbvjahwcgzmutq")

    def write_to_file(self, MODULE):
        with open(self.filename, "ab") as file:
            pickle.dump(self.products, file)
            print(Fore.WHITE, f"[{MODULE}] - Write completed => ", self.filename)

    def add(self, key, value):
        self.products[key] = value

    def get_products_length(self):
        return len(self.products.keys())

    def add_module(self, module):
        self.modules.append(module)

    def completed(self, module):
        self.modules.remove(module)
        print(f"[{module}] - returned")
        self.mail(module)

    def mail(self, module):
        msg = MIMEMultipart('alternative')
        msg['Subject'] = "Scrap completed"
        msg['From'] = "idiotpyscripts@gmail.com"
        msg['To'] = self.email
        text = "Your scrap query " + f"'{module}'" + " was successfully completed scrapping. Please get your data from the app "
        html = """\
                <html>
                <head>
                    <title>Scraping completed</title>
                </head>
                <body>
                    <style>
                        body {
                            background-color: black;
                        }
                        h4 {
                            color: aquamarine;
                        }
                        button {
                            height: 40px;
                            width: 100px;
                            color: white;
                            background-color: blue;
                            border-radius: 10px;
                            border-color: white;
                            margin-left: 50%;
                            margin-right: 50%;
                        }
                    </style>
                    <h4>Your scrap query <placeholder> is ready <a href='http://productscrapper.com/results'>Open app</a></h4>
                    <p><strong>Remember</strong>, if you have closed the app or the app was stopped working in the background you will lose the data.</p>
                </body>
                </html>
                """
        attach_file_name = self.filename.replace("cache", "json")
        with open(self.filename.replace("cache", "json"), "w") as file:
            with  open(self.filename, "rb") as cache:
                data = pickle.load(cache)
                data = json.dumps(data)
                # f = Fernet(key)
                # enc_data = f.encrypt(data.encode())
                file.write(data)

        attach_file = open(attach_file_name, 'rb')  # Open the file as binary mode
        payload = MIMEBase('application', 'octate-stream')
        payload.set_payload((attach_file).read())
        encoders.encode_base64(payload)  # encode the attachment
        # add payload header with filename
        payload.add_header('Content-Decomposition', f'attachment; filename="{self.filename}"')
        part1 = MIMEText(text)
        part2 = MIMEText(html, 'html')
        msg.attach(part1)
        msg.attach(part2)
        msg.attach(payload)

        self.server.sendmail("idiotpyscripts@gmail.com", self.email, msg.as_string())
        self.server.quit()

        attach_file.close()
        try:
            os.remove(attach_file_name)
        except FileExistsError:
            print("File not present")


# pro = Products("77c7960e890deddebb7ff2e55e340d2ed1708368.cache", "predatorsha2002@gmail.com", "ram")
# pro.add_module("Flipkart")
# pro.completed("Flipkart")
