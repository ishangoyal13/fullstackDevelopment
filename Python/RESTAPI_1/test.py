import requests
# this lets send post, get requests etc

BASE = "http://127.0.0.1:5000/"

#data = [{"likes" : 10, "name": "Tim", "views": 2000},
#		{"likes" : 12, "name": "John", "views": 1000},
#		{"likes" : 5, "name": "Ram", "views": 3000}]

#for i in range (len (data)):
#	response = requests.put (BASE + "video/" + str (i), data [i])
# put gives data in form of json

#id = input ()
response = requests.patch (BASE + "video/2", {"views": 99})
print (response.json())