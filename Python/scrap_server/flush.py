import os
import time
from datetime import datetime
from os import path, listdir
from time import ctime


def flush():
    print("Flush started")
    while True:
        for file in listdir():
            if ".cache" in file:
                filemtime = datetime.strptime(ctime(path.getmtime(file)), "%a %b %d %H:%M:%S %Y")
                diff = datetime.now() - filemtime
                print(file, "=>", filemtime, f"Deletion in {diff} min's")
                if str(diff).split(":")[0] >= "1":
                    os.remove(file)
        time.sleep(300)
