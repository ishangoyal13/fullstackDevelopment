import json
import pickle
import threading
import time
from hashlib import sha1
from os import path, remove

from flask import Flask, request, jsonify
import flush
import amazon
# link = ngrok.connect(proto="http", port=5000)
from flipkart import Flipkart
from products import Products

app = Flask(__name__)

maxItem = 100
data = dict()
method = 0

threading.Thread(target=flush.flush).start()

# def pastelink():
#     chrome.get("https://pastebin.com/NQNdrkGW")
#     chrome.find_element_by_xpath("//a[@class='btn-sign sign-in']").click()
#     time.sleep(3)
#     chrome.find_element_by_xpath("//input[@id='loginform-username']").send_keys("hiruthic")
#     chrome.find_element_by_xpath("//input[@id='loginform-password']").send_keys("6R4#&MyNAxwiXAm")
#     chrome.find_element_by_xpath("//button[@class='btn -big']").click()
#     time.sleep(3)
#
#     chrome.find_element_by_xpath("//a[contains(text(),'edit')]").click()
#     time.sleep(3)
#     chrome.find_element_by_xpath("//textarea[@class='textarea']").clear().send_keys(link.encode());


@app.route("/test")
def test():
    return "test"

@app.route('/', methods=["GET"])
def hello_world():
    data["product"] = str(request.args["product"])
    data["country"] = str(request.args["country"])
    data["length"] = int(request.args["length"])
    data["timestamp"] = str(request.args["timestamp"])
    data["override"] = str(request.args["override"])
    data["options"] = json.loads(request.args["options"])

    print(data["options"])
    products = scrap()
    return jsonify(products)


@app.route("/cache", methods=["GET"])
def get_cache():
    arg0 = str(request.args["timestamp"])
    arg1 = str(request.args["product"])
    filename = sha1(str(arg1).encode()).hexdigest() + ".cache"
    if path.exists(filename):
        with open(filename, "rb") as file:
            cache_data = pickle.load(file)
            cache_data["cache"] = True
            return jsonify(cache_data)
    else:
        return jsonify(-1)


def scrap(recall=False):
    filename = sha1(str(data["product"]).encode()).hexdigest() + ".cache"
    data["filename"] = filename
    products = Products(filename, data["options"]["email"], data["product"])

    if path.exists(filename) and recall == False and data["override"] == "false":
        print("File present in cache")
        with open(filename, "rb") as file:
            cache_data = pickle.load(file)
            cache_data["cache"] = True
            print(len(cache_data.keys()))
            if len(cache_data.keys()) >= data["length"]:
                return cache_data
            else:
                scrap(recall=True)
    else:
        if path.exists(filename):
            remove(filename)
        start = time.time()
        global method, maxItem
        maxItem = data["length"] * 2
        noItem = 0

        if data["options"]["sites"]["Amazon"]:
            products.add_module("Amazon")
            amazon_scrapper = amazon.Amazon(data, maxItem, noItem, products)
            threading.Thread(target=amazon_scrapper.run).start()
        if data["options"]["sites"]["Flipkart"]:
            products.add_module("Flipkart")
            flipkart_scrapper = Flipkart(data, maxItem, noItem, products)
            threading.Thread(target=flipkart_scrapper.run).start()
        if data["options"]["sites"]["ebay"]:
            products.add_module("ebay")
            print("ebay")
            # TODO: ebay scrapper

        return 0


if __name__ == '__main__':
    app.run(debug=True)
