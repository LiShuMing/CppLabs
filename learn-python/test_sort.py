

def test_sort_1():
    datas = []
    for i in range(1, 100):
        data = {"key":1, "c0":i}
        datas.append(data)
    print(datas)
    new_list = sorted(datas, key = lambda x: x["c0"], reverse = False)
    print(new_list)

    for i in (0, 1, 100, -1):
        for j in (0, 10):
            print("-----------j:%s i:%s--------" % (j, i))
            print(datas[j:i])


test_sort_1()
