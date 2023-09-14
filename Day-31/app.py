from flask import Flask,request
import json

app = Flask('Time Table')

@app.route('/')
def hello():
    return "Hello"

@app.route('/timetable',methods=["GET"])
def timetable():
    return json.dumps({"timetable":"nahi milega"})


@app.route('/route',methods=["POST"])
def hello2():
    name = "No name"
    print(request.get_json())
    return request.get_json()

if __name__ == "__main__":
    app.run(debug=True)