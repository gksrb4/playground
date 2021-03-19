
def BinarySearch(cw, weight):
    first = 0
    last = len(cw)-1
    index = -1
    while (first <= last) and (index == -1):
        mid = (first+last)//2
        if cw[mid] == weight:
            index = mid
        else:
            if val<cw[mid]:
                last = mid -1
            else:
                first = mid +1
    return index

def get_possible_truck_index(cw, weight):
    for i,c in enumerate(cw):
        if c[0] >= weight:
            return i
    return -1

def solution(truck, w):
    answer = []
    cw = []
    for i,t in enumerate(truck):
        cw.append([t, i+1])
    for i in w:
        answer.append(-1)
    for li, l in enumerate(w):
        cw.sort()
        i = get_possible_truck_index(cw, l)
        for ti, t in enumerate(cw[i:]):
            if cw[ti][0] >= l:
                cw[ti][0] -= l
                answer[li] = cw[ti][1]
                break
    return answer

ret = solution(
    [1,4,5,2,4],
    [2,4,4,3,2]
)
print(ret)