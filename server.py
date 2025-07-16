from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/train')
def query_train():
    # 获取参数
    from_station = request.args.get('from', '')
    to_station = request.args.get('to', '')
    date = request.args.get('date', '')

    # 固定返回几条假数据，字段内容更真实
    trains = [
        {
            "trainid": "G1234",
            "time": "07:12",
            "depart": from_station or "北京南",
            "arrive": to_station or "上海虹桥",
            "date": date or "2025-07-17",
            "price": 553.5,
            "duration": "4小时28分",
            "seat": "二等座",
        },
        {
            "trainid": "D5678",
            "time": "09:45",
            "depart": from_station or "北京南",
            "arrive": to_station or "上海虹桥",
            "date": date or "2025-07-17",
            "price": 415.0,
            "duration": "7小时13分",
            "seat": "一等座",
        },
        {
            "trainid": "Z999",
            "time": "13:21",
            "depart": from_station or "北京",
            "arrive": to_station or "上海",
            "date": date or "2025-07-17",
            "price": 312.0,
            "duration": "13小时28分",
            "seat": "硬卧",
        }
    ]

    # 返回 JSON 数组
    return jsonify(trains)

if __name__ == '__main__':
    app.run(host='127.0.0.1', port=8080, debug=True)