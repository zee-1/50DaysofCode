import requests

import json
j = {"name":"zee"}

req = requests.request("GET","http://127.0.0.1:5000/timetable",json=j)
print(req.status_code)
print(req.json())