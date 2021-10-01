import pickle
import time
from os import environ

from colorama import init, Fore
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException

init()

chrome_options = webdriver.ChromeOptions()
chrome_options.binary_location = environ.get("GOOGLE_CHROME_BIN")
chrome_options.add_argument("--headless")
chrome_options.add_argument("--disable-dev-shm-usage")
chrome_options.add_argument("--no-sandbox")
chrome_options.add_argument("user-agent=[Chrome/80.0.3987.116]")

chrome = webdriver.Chrome(
    executable_path=environ.get("CHROMEDRIVER_PATH"),
    chrome_options=chrome_options)

MODULE = "Amazon"
links = {"Amazon": ["https://www.amazon.ext/s?k=",
                    {
                        "next": "//a[contains(text(),'Next')]",
                        "maxPages": "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[19]/span[1]/div[1]/div[1]/ul[1]/li[6]",
                        "url": [
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/h2[1]/a[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/div[2]/div[1]/div[1]/div[1]/div[1]/div[1]/h2[1]/a[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[5]/div[1]/span[1]/div[1]/div[1]/span[1]/div[1]/div[1]/div[1]/div[1]/div[1]/ol[1]/li[placeholder]/div[1]/div[1]/div[2]/h2[1]/a[1]/span[1]"],
                        "name": [
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/h2[1]/a[1]/span[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/div[2]/div[1]/div[1]/div[1]/div[1]/div[1]/h2[1]/a[1]/span[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[5]/div[1]/span[1]/div[1]/div[1]/span[1]/div[1]/div[1]/div[1]/div[1]/div[1]/ol[1]/li[placeholder]/div[1]/div[1]/div[2]/h2[1]/a[1]/span[1]"],
                        "price": [
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[4]/div[1]/div[1]/a[1]/span[1]/span[2]/span[2]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/div[2]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/div[1]/a[1]/span[1]/span[2]/span[2]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[5]/div[1]/span[1]/div[1]/div[1]/span[1]/div[1]/div[1]/div[1]/div[1]/div[1]/ol[1]/li[placeholder]/div[1]/div[1]/div[4]/div[1]/div[1]/a[1]/span[1]/span[2]/span[2]"],
                        "currency": [
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[4]/div[1]/div[1]/a[1]/span[1]/span[2]/span[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/div[2]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/div[1]/a[1]/span[1]/span[2]/span[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[5]/div[1]/span[1]/div[1]/div[1]/span[1]/div[1]/div[1]/div[1]/div[1]/div[1]/ol[1]/li[placeholder]/div[1]/div[1]/div[4]/div[1]/div[1]/a[1]/span[1]/span[2]/span[1]"],
                        "image": [
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/span[1]/a[1]/div[1]/img[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[placeholder]/div[1]/span[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/span[1]/a[1]/div[1]/img[1]",
                            "/html[1]/body[1]/div[1]/div[2]/div[1]/div[1]/div[1]/div[1]/span[3]/div[2]/div[5]/div[1]/span[1]/div[1]/div[1]/span[1]/div[1]/div[1]/div[1]/div[1]/div[1]/ol[1]/li[placeholder]/div[1]/div[1]/span[1]/a[1]/div[1]/img[1]"],
                    }]}


def print_(a):
    print(a)


class Amazon:
    def __init__(self, data, maxItem, noItem, products):
        self.data = data
        self.maxItem = maxItem
        self.noItem = noItem
        self.products = products
        self.method = 1
        product_url = data['product']
        # chrome.execute_script(f"window.open('{product_url}');")  # Pre-opening new tab
        # chrome.switch_to_window(chrome.window_handles[0])

    def run(self):
        print(Fore.LIGHTBLUE_EX, f"Module started: {MODULE}")
        filename = self.data["filename"]
        url = links["Amazon"][0].replace("ext", self.data["country"]) + self.data["product"]
        start = time.time()
        chrome.get(url)
        maxPages = 10
        try:
            time.sleep(2)
            maxPages = int(chrome.find_element_by_xpath(links["Amazon"][1]["maxPages"]).text)
        except NoSuchElementException:
            print(Fore.MAGENTA, f"[{MODULE}] - Cannot get max pages value")
        while maxPages != 0:
            whileStart = time.time()
            if self.maxItem <= self.products.get_products_length():
                print(Fore.BLACK, f"[{MODULE}] - request length reached -", time.time() - start)
                maxPages = 0
                self.products.write_to_file(MODULE)
                chrome.close()
                self.products.completed(MODULE)
                return
            for i in range(100):  # Method 1
                self.noItem = 0
                try:
                    name = chrome.find_element_by_xpath(
                        links["Amazon"][1]["name"][0].replace("placeholder", str(i))).text
                    price = chrome.find_element_by_xpath(
                        links["Amazon"][1]["price"][0].replace("placeholder", str(i))).text
                    currency = chrome.find_element_by_xpath(
                        links["Amazon"][1]["currency"][0].replace("placeholder", str(i))).text
                    image = chrome.find_element_by_xpath(
                        links["Amazon"][1]["image"][0].replace("placeholder", str(i))).get_attribute("src")
                    url = chrome.find_element_by_xpath(
                        links["Amazon"][1]["url"][0].replace("placeholder", str(i))).get_attribute(
                        "href")
                    value = {"price": price, "currency": currency, "image": image, "url": url,
                                           "source": MODULE}
                    self.products.add(name, value)
                except NoSuchElementException:
                    self.noItem += 1
                # print(f"Method 1 completed => {self.noItem} ({time.time() - start}) - [Remaining pages: {maxPages}]")

                try:
                    name = chrome.find_element_by_xpath(
                        links["Amazon"][1]["name"][1].replace("placeholder", str(i))).text
                    price = chrome.find_element_by_xpath(
                        links["Amazon"][1]["price"][1].replace("placeholder", str(i))).text
                    currency = chrome.find_element_by_xpath(
                        links["Amazon"][1]["currency"][1].replace("placeholder", str(i))).text
                    image = chrome.find_element_by_xpath(
                        links["Amazon"][1]["image"][1].replace("placeholder", str(i))).get_attribute("src")
                    url = chrome.find_element_by_xpath(
                        links["Amazon"][1]["url"][1].replace("placeholder", str(i))).get_attribute(
                        "href")
                    value = {"price": price, "currency": currency, "image": image, "url": url,
                                           "source": MODULE}
                    self.products.add(name, value)
                except NoSuchElementException:
                    self.noItem += 1
                # print(f"Method 2 completed => {self.noItem} ({time.time() - start})")

                try:
                    name = chrome.find_element_by_xpath(
                        links["Amazon"][1]["name"][2].replace("placeholder", str(i))).text
                    price = chrome.find_element_by_xpath(
                        links["Amazon"][1]["price"][2].replace("placeholder", str(i))).text
                    currency = chrome.find_element_by_xpath(
                        links["Amazon"][1]["currency"][2].replace("placeholder", str(i))).text
                    image = chrome.find_element_by_xpath(
                        links["Amazon"][1]["image"][2].replace("placeholder", str(i))).get_attribute("src")
                    url = chrome.find_element_by_xpath(
                        links["Amazon"][1]["url"][2].replace("placeholder", str(i))).get_attribute(
                        "href")
                    value = {"price": price, "currency": currency, "image": image, "url": url,
                                           "source": MODULE}
                    self.products.add(name, value)
                except NoSuchElementException:
                    self.noItem += 1
                # print(f"Method 3 completed => {self.noItem} ({time.time() - start}) - [Remaining pages: {maxPages}]")

            print(Fore.WHITE, f"[{MODULE}] - Total products found so far:", self.products.get_products_length(), "- ",
                  time.time() - whileStart,
                  "sec's.")
            try:
                chrome.find_element_by_xpath(links["Amazon"][1]["next"]).click()
                time.sleep(2)
            except NoSuchElementException:
                print(Fore.RED, f"[{MODULE}] - No element while clicking")

            # with open(filename, "ab") as file:
            #     pickle.dump(self.products, file)
            #     print(Fore.GREEN, f"[{MODULE}] - Write completed (checkpoint) => ", filename)
            #     # chrome.close()

            maxPages -= 1
        self.products.write_to_file(MODULE)
        return
