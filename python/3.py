
min_cnt = -1
trace = []

def change_color(c):
    if c == 'R':
        return 'G'
    elif c == 'G':
        return 'B'
    elif c == 'B':
        return 'R'

def change_colors(bulbs, start, k):
    for i in range(0,k):
        bulbs[start+i] = change_color(bulbs[start+i])
    return bulbs

def dfs(depth, n, k, bulbs):
    global min_cnt, trace
    for t in trace:
        if depth != 0 and ''.join(t) == ''.join(bulbs):
            return
    if min_cnt != -1 and min_cnt <= depth:
        return
    if bulbs[0] == 'R':
        for i,c in enumerate(bulbs):
            if c != 'R':
                bulbs = bulbs[i:]
                break
            if i == len(bulbs) - 1:
                min_cnt = min(min_cnt, depth) if min_cnt != -1 else depth
                trace = []
                trace.append(bulbs)
                return
    if bulbs[len(bulbs)-1] == 'R':
        for i,_ in enumerate(bulbs):
            c = bulbs[len(bulbs)-1-i]
            if c != 'R':
                bulbs = bulbs[:-i]
                trace = []
                trace.append(bulbs)
                break
    n = len(bulbs)
    if k > n:
        return
    if k == n:
        for c in bulbs:
            if bulbs[0] != c:
                return
    for i in range(0, n-k+1):
        _bulbs = bulbs[:]
        _bulbs = change_colors(_bulbs, i, k)
        dfs(depth+1, n, k, _bulbs)
        trace.append(_bulbs)

def solution(n, k, bulbs):
    global min_cnt
    answer = -1
    min_cnt = -1
    trace.append(bulbs)
    dfs(0, n, k, list(bulbs))
    answer = min_cnt
    print(answer)
    return answer

# ret = solution(
#     6,
#     3,
#     "RBGRGB"
# )

ret = solution(
    6,
    3,
    "RBGRGBRRRRRRRRRR"
)

ret = solution(
    3,
    2,
    "BGG"
)

ret = solution(
    4,
    2,
    "GBBG"
)
test = "ABCDE"
print(test[:-2])