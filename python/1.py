

cost = 0
min_cost = 0

visited = []

def get_next_position(i, x, y):
    _x = x
    _y = y
    if i == 0:
        _x += 1
    elif i == 1:
        _y += 1
    elif i == 2:
        _x -= 1
    elif i == 3:
        _y -= 1
    return _x, _y

def is_possible(N, k, x, y, nx, ny):
    if nx == ny:
        return False
    if max(abs(x-k), abs(y-k)) > max(abs(nx-k), abs(ny-k)):
        return False
    if visited[N*ny+nx]:
        return False
    return True

def binary_condition(N, x, y):
    return (x == 0 or x == N-1 or y == 0 or y == N-1)


def dfs(depth, N, x, y, board, cost):
    global min_cost, visited
    if binary_condition(N, x, y):
        if min_cost == 0:
            min_cost = cost
        else:
            min_cost = min(min_cost, cost)
        visited[N*y+x] = False
        return
    k = int(N/2)
    for i in range(0, 4):
        nx, ny = get_next_position(i, x, y)
        if is_possible(N, k, x, y, nx, ny):
            visited[N*ny+nx] = True
            cost += board[N*ny+nx]
            dfs(depth+1, N, nx, ny, board, cost)

def solution(N, board):
    global min_cost, visited
    answer = 0
    for i in range(0, N*N):
        visited.append(False)
    dfs(1, N, int(N/2), int(N/2), board, 0)
    answer = min_cost
    return answer


solution(5,
    [9, 3, 9, 9, 9, 5, 2, 7, 8, 9, 8, 1, 5, 8, 9, 6, 1, 8, 7, 9, 9, 9, 8, 9, 9]
)

