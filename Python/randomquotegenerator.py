import requests

url = 'https://api.quotable.io/random'

r = requests.get(url)
quote = r.json()
#print(quote)
print(quote['content'])
print('     -',quote['author'])
