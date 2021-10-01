# Import requirements
import requests

# set the website you want to test
website = "github.com"

# read all subdomains
file = open("subdomains.txt")
content = file.read()

# make a list of all the subdomains so that they can be iterated easily
subdomains = content.splitlines()

# empty list that will store all the correct subdomains
correct_subdomains = []

for subdomain in subdomains:
    # url that will be tested
    url = f"https://{subdomain}.{website}"

    try:
        # send a get request to the constructed url
        requests.get(url)
    except requests.ConnectionError:
        # if connection error is raised that means url does not exist
        pass
    else:
        # if we reach here this means url exists
        print(f"Subdomain Discovered: {url}")
        correct_subdomains.append(url)

# create a new file named found_subdomain and write all the discovered subdomains in it
with open("found_subdomains.txt", "w") as f:
    for subdomain in correct_subdomains:
        print(subdomain, file=f)
