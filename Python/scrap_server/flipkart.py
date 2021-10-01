import time
from copy import deepcopy
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
    
MODULE = "Flipkart"
links = {"Flipkart": ["https://www.flipkart.com/search?q=",
                      {
                          "next": "//span[contains(text(),'Next')]",
                          "name": [
                              "/html[1]/body[1]/div[1]/div[1]/div[3]/div[2]/div[1]/div[2]/div[line]/div[1]/div[placeholder]/div[1]/a[2]"],
                          "image": [
                              "/html[1]/body[1]/div[1]/div[1]/div[3]/div[2]/div[1]/div[2]/div[line]/div[1]/div[placeholder]/div[1]/a[1]/div[1]/div[1]/div[1]/img[1]"],
                          "price": [
                              "/html[1]/body[1]/div[1]/div[1]/div[3]/div[2]/div[1]/div[2]/div[line]/div[1]/div[placeholder]/div[1]/a[3]/div[1]/div[1]"],
                      }
                      ]}


def line_replace(line):
    copy = deepcopy(links)
    for key in copy["Flipkart"][1].keys():
        if key == "next" or key == "maxPages":
            continue
        for value in copy["Flipkart"][1][key]:
            if "line" in value:
                i = copy["Flipkart"][1][key].index(value)
                copy["Flipkart"][1][key].pop(i)
                copy["Flipkart"][1][key].insert(i, value.replace("line", str(line)))

    return copy


class Flipkart:
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
        url = links["Flipkart"][0].replace("ext", self.data["country"]) + self.data["product"]
        start = time.time()
        chrome.get(url)
        maxPages = 10

        while maxPages != 0:
            whileStart = time.time()
            if self.maxItem <= self.products.get_products_length():
                print(Fore.BLACK, f"[{MODULE}] - request length reached -", time.time() - start)
                maxPages = 0
                self.products.write_to_file(MODULE)
                chrome.close()
                self.products.completed(MODULE)
                return

            for i in range(1, 5):
                self.noItem = 0
                for line in range(1, 11):
                    copy = line_replace(line)
                    try:
                        name = chrome.find_element_by_xpath(
                            copy["Flipkart"][1]["name"][0].replace("placeholder", str(i))).text
                        price = chrome.find_element_by_xpath(
                            copy["Flipkart"][1]["price"][0].replace("placeholder", str(i))).text[1:]
                        currency = price[0]
                        image = chrome.find_element_by_xpath(
                            copy["Flipkart"][1]["image"][0].replace("placeholder", str(i))).get_attribute("src")
                        url = chrome.find_element_by_xpath(
                            copy["Flipkart"][1]["name"][0].replace("placeholder", str(i))).get_attribute("href")
                        value = {"price": price, "currency": currency, "image": image, "url": url, "source": MODULE}
                        self.products.add(name, value)

                    except NoSuchElementException:
                        self.noItem += 1

            try:
                chrome.find_element_by_xpath(links["Flipkart"][1]["next"]).click()
                time.sleep(2)
            except NoSuchElementException:
                print(f"[{MODULE}] - No next button")

            # with open(filename, "ab") as file:
            #     pickle.dump(self.products, file)
            #     print(Fore.GREEN, f"[{MODULE}] - Write completed (checkpoint) => ", filename)

            print(Fore.WHITE, f"[{MODULE}] - Total products found so far:", self.products.get_products_length(),
                  "- ", time.time() - whileStart,
                  "sec's.")
        self.products.write_to_file(MODULE)
        chrome.close()
        return
