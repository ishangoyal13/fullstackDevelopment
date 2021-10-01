import requests
import sys

def get_stats(country):
    r = requests.get(f'https://api.covid19api.com/country/{country}')
    try:
        data = r.json()[-1]
    except KeyError:
        print('Country name is incorrect.')
        sys.exit()

    country_code = data['CountryCode']
    province = data['Province']
    city = data['City']
    city_code = data['CityCode']
    lat = data['Lat']
    lon = data['Lon']
    confirmed = data['Confirmed']
    deaths = data['Deaths']
    recovered = data['Recovered']
    active = data['Active']
    date = data['Date']

    print(f'\n\nCountry: {country}\nCountry Code: {country_code}')
    print(f'City: {city}\nCity code: {city_code}')
    print(f'Province: {province}')
    print(f'Longitude: {lon}\nLatitude: {lat}')
    print(f'Confirmed cases: {confirmed}\nDeaths: {deaths}')
    print(f'Recovered: {recovered}\nActive: {active}\nDate: {date}')

if __name__ == '__main__':
    country = input('Country name: ')
    get_stats(country)
