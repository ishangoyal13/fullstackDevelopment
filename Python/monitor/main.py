import matplotlib.pyplot as plt
import json
import atexit
import win32api
import argparse
from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive

import monitor as mon_mod


parser = argparse.ArgumentParser("Some usefull flags")
parser.add_argument("-vis", "--visualize", help="Just visualize", action="store_true")
parser.add_argument("-no-up", "--no-upload", help="Dont upload the data to server", action="store_true")

args = parser.parse_args()

drive = None

appsToMonitor = None
appNames = None
appColors = None
appIcons = None
timeout = 0
uploadPerEpoch = 1
track = {}

def plot():
    # Get app name for the corresponding process
    labels = [appNames[key] for key in appNames.keys() if key in track.keys()]
    sizes = [size["timeSpentOnWork"]
            for key, size in track.items() if key != "lastUpdated"]  # Get all the apps working time
    # Colors denoting each application
    colors = [color for app, color in appColors.items() if app in labels]
    explode = [0.05] * len(labels)

    fig1, ax1 = plt.subplots()

    ax1.pie(sizes, colors=colors, labels=labels,
            autopct="%1.1f%%", startangle=90, explode=explode)

    # draw circle
    centre_circle = plt.Circle((0, 0), 0.70, fc='white')
    fig = plt.gcf()
    fig.gca().add_artist(centre_circle)
    # Equal aspect ratio ensures that pie is drawn as a circle
    ax1.axis('equal')
    plt.tight_layout()
    plt.legend([f"{label}: {size} min's" for label, size in zip(labels, sizes)])
    plt.show()

        
def exit_handler(sig=None):
    if not args.visualize:  # Write data
        print("Writing to file...", end=" ")
        with open("tracking.json", "w+") as file:
            for key in track.keys():
                if key == "lastUpdated":
                    continue
                track[key]["appName"] = appNames[key]
                track[key]["appIcon"] = appIcons[appNames[key]]
            json.dump(track, file)
        print("Done")
    
    if not args.no_upload and not args.visualize:  # Upload file to Google Drive
        print("Uploading file...", end=" ")
        # file = {'file': open("tracking.json", 'rb')}
        # data = requests.post("https://toxic-cat.herokuapp.com/upload?pass=sha", files=file)
        # if data.status_code == 200:
        #     print("Done.")
        # else:
        #     print(f"Error: {data.status_code} - {data.reason}")
        tracking = drive.CreateFile({"title": "tracking.json", 'mimeType':'application/json'})
        tracking.SetContentFile("tracking.json")
        tracking.update()
        tracking = None
        print("Done.")
    return

atexit.register(exit_handler)
# win32api.SetConsoleCtrlHandler(exit_handler)

def upload():
    tracking = drive.CreateFile({"title": "tracking.json", 'mimeType':'application/json', "id": "1PHdJYxWWb7SrudjOeIDiDvK-gGE1JPvY"})
    tracking_content = tracking.GetContentString()
    lines = str()
    for line in open("tracking.json", "r").readlines():
        lines += line
    tracking_content = lines
    tracking.SetContentString(tracking_content)
    tracking.Upload()
    tracking = None  

def exit_handler(sig=None):
    if not args.visualize:  # Write data
        print("Writing to file...", end=" ")
        with open("tracking.json", "w+") as file:
            for key in track.keys():
                if key == "lastUpdated":
                    continue
                track[key]["appName"] = appNames[key]
                track[key]["appIcon"] = appIcons[appNames[key]]
            json.dump(track, file)
        print("Done")
    
    if not args.no_upload and not args.visualize:  # Upload file to Google Drive
        print("Uploading file...", end=" ")
        # file = {'file': open("tracking.json", 'rb')}
        # data = requests.post("https://toxic-cat.herokuapp.com/upload?pass=sha", files=file)
        # if data.status_code == 200:
        #     print("Done.")
        # else:
        #     print(f"Error: {data.status_code} - {data.reason}")
        upload()
        print("Done.")
    return

atexit.register(exit_handler)
# win32api.SetConsoleCtrlHandler(exit_handler)

if args.visualize == True:
    print("Reading data and config...", end=" ")
    with open("config.json", "r") as file:  # Read the settings from config.json
        jsonImported = json.loads(file.read())
        appsToMonitor = jsonImported["monitorApps"]
        appNames = jsonImported["appNames"]
        appColors = jsonImported["appColors"]
        # appIcons = jsonImported["appIcons"]

    with open("tracking.json", "r") as file:
        track = json.load(file)
        print("Done.")
        plot()
else:
    if not args.no_upload:  # If no objection on upload, login with OAuth
        gauth = GoogleAuth()
        gauth.LocalWebserverAuth()

        drive = GoogleDrive(gauth)

    print("Reading config...", end=" ")
    with open("config.json", "r") as file:  # Read the settings from config.json
        jsonImported = json.loads(file.read())
        appsToMonitor = jsonImported["monitorApps"]
        appNames = jsonImported["appNames"]
        appColors = jsonImported["appColors"]
        appIcons = jsonImported["appIcons"]
        timeout = jsonImported["refreshTime"]
        uploadPerEpoch = jsonImported["uploadPerEpoch"]
        print("Done.")
        print(f"Refresh rate: {timeout}, Upload interval: {uploadPerEpoch}")

    print("Populating data (if exist)", end=" ")
    with open("tracking.json", "r") as file:  # Populate existing data is exist
        try: 
            track = json.load(file)
            print("Done.")
        except: pass

    print("Monitoring: ")
    data = [track, appsToMonitor, appNames, appIcons, appColors, timeout, uploadPerEpoch, drive]
    mon_mod.monitor(data)  # Start monitoring
    plot()  # Plot it


# print(track)

