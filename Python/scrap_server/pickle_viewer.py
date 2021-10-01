import pickle
from os import path, listdir

try:
    import pandas as pd
except ImportError:
    pass

for file in listdir():
    if ".cache" in file:
        a = int(input("Type: "))
        if a == 0:
            with open(file, "rb") as file:
                data = pickle.load(file)
                for k, v in data.items():
                    print(k, "=>", v)
            print(len(data.keys()))
        else:
            with open(file, "rb") as file:
                data = pickle.load(file)
                df = pd.DataFrame(data)
                print(df)

        
