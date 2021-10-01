from bs4 import BeautifulSoup
import requests
import spotipy
from spotipy.oauth2 import SpotifyOAuth
OAUTH_AUTHORIZE_URL = 'https://accounts.spotify.com/authorize'
OAUTH_TOKEN_URL = 'https://accounts.spotify.com/api/token'
clientID = "****************************"   # your spotify clientID
clientSecret = "******************************"  # your spotify clientSecret
redirectURI = "https://example.com"
scope = "playlist-modify-private"


response = requests.get("https://www.billboard.com/charts/hot-100/YYYY-MM-DD")  #change YYYY-MM-DD to specific date



webpage = response.text
soup = BeautifulSoup(webpage, "html.parser")
wrapper = soup.find(name="div", class_="chart-list__wrapper")


sp = spotipy.Spotify(auth_manager=SpotifyOAuth(
    client_id=clientID, client_secret=clientSecret, redirect_uri=redirectURI, scope=scope))


results = sp.playlist("**************your playlist id here*******************") # google spotify playlist id


artists = [artist.getText() for artist in soup.find_all(
    name="span", class_="chart-element__information__artist text--truncate color--secondary")]
songs = [song.getText() for song in soup.find_all(
    name="span", class_="chart-element__information__song text--truncate color--primary")]

song_names = []
song_uris =[]
for _ in range(len(songs)):
    song_names.append(f"{songs[_]}")
    print(f"**********************{songs[_]} by {artists[_]} added**************************")


for song in song_names:
    result = sp.search(q=f"track:{song}", type="track")
    # print(result)
    try:
        uri = result["tracks"]["items"][0]["uri"]
        song_uris.append(uri)
    except IndexError:
        print(f"{song} doesn't exist in Spotify. Skipped.")



one = song_uris[_]
print(one)
sp.playlist_add_items(playlist_id="****************your playlist id********************", items=song_uris)
