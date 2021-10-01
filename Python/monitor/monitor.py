import datetime
import subprocess
import time
import json
import re

drive = None
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

# Core stuff
def monitor(data):
    global drive
    track, appsToMonitor, appNames, appIcons, appColors, timeout, uploadPerEpoch, drive = data
    try:
        monitored = 0  # Iteration of monitor's
        while True:
            runningApps = re.findall(r"\w{1,}.exe", subprocess.check_output(
                "tasklist").decode())  # Get output for tasklist from cmd

            start = time.time()
            for app in runningApps:
                for key, value in appsToMonitor.items():
                    if app in value:
                        # print(app, [creationTime.strip(".") for creationTime in re.findall(r"\d{1,}\.", subprocess.check_output(f"wmic process where Name='{app}' get CreationDate").decode())])

                        try:  # Somtimes it causes an error
                            date = str(min([int(creationTime.strip(".")) for creationTime in re.findall(r"\d{1,}\.", subprocess.check_output(
                                f"wmic process where Name='{app}' get CreationDate").decode())]))  # Get only the max time creation among all child processes
                        except ValueError:
                            continue
                        
                        year = int(date[0:4])
                        month = int(date[4:6])
                        day = int(date[7:8])

                        creationTime = datetime.datetime.strptime(
                            f"{date[0:4]}/{date[4:6]}/{date[7:8]} {date[8:10]}-{date[10:12]}-{date[12:-1]}", "%Y/%m/%d %H-%M-%S").strftime("%d-%m-%Y %H:%M:%S")  # Generate clean date and time
                        track[app] = {
                            "creationTime": creationTime,
                            # Calculate total time spent and use divmod on timedelta object with 60 to get (min's, sec's)[0] -> Take only the minutes
                            "timeSpentOnWork": divmod((datetime.datetime.now() - datetime.datetime.strptime(creationTime, "%d-%m-%Y %H:%M:%S")).total_seconds(), 60)[0],
                            "category": key
                        }

            monitored += 1
            print(
                f"[{monitored:<3}] Processes calculated: {time.time() - start} [{len(track.keys())}]")  # Some logging

            with open("tracking.json", "r") as file:  # Update track dictionary with existing data
                try:  # If there is no process before adding the value raises error
                    tracking = json.load(file)
                    for key, value in tracking.items():
                        if track.get(key) == None:
                            track[key] = value
                        else:
                            track[key] += value
                except:
                    pass

            with open("tracking.json", "w+") as file:  # Store the data on each iteration
                for key in track.keys():
                    if key == "lastUpdated":
                        continue
                    track[key]["appName"] = appNames[key]
                    track[key]["appIcon"] = appIcons[appNames[key]]
                    track[key]["appColor"] = appColors[appNames[key]]

                track["lastUpdated"] = datetime.datetime.now().strftime(
                    "%d-%m-%Y %H:%M:%S")
                json.dump(track, file)

            if monitored % uploadPerEpoch == 0:
                print("Epoch completed, Uploading...", end=" ")
                upload()
                print("Done.")

            time.sleep(timeout)
    except KeyboardInterrupt:
        return
