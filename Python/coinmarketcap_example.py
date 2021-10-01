import requests
import json
from tabulate import tabulate

# yon can get your token over at https://coinmarketcap.com/api/
API_KEY = ""

URL = "https://pro-api.coinmarketcap.com"


def get_data():
    headers = {
        "X-CMC_PRO_API_KEY": API_KEY,
        "Accepts": "application/json"
    }
    parameters = {
        "limit": "20"
    }

    r = requests.get(
        f"{URL}/v1/cryptocurrency/listings/latest", headers=headers, params=parameters)

    if r.status_code == 200:
        return json.loads(r.text)
    else:
        print(f"ERROR FETCHING THE API : \n {r.text}")


# print(json.dumps(get_data(), indent=4))


def render():
    data = get_data()
    table = []
    n = 0
    while n != len(data['data']):
        for value in data['data'][n]["quote"].values():
            row = []
            # print("\n\n", value)
            row.append(data['data'][n]['name'])
            for i in value.values():
                row.append(i)
            table.append(row)
        n += 1
    print(table)
    print(tabulate(table, headers=[
          'currency',
          'price',
          'volume_24h',
          'percent_change_1h',
          'percent_change_24h',
          "percent_change_7d",
          "percent_change_30d",
          'percent_change_60d',
          "percent_change_90d",
          "market_cap",
          "market_cap_dominance",
          "fully_diluted_market_cap",
          "last_updated"]))


render()
input("")
