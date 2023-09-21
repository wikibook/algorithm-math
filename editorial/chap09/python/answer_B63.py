# 입력
H, W = map(int, input().split())
sx, sy = map(int, input().split())
sx -= 1
sy -= 1
gx, gy = map(int, input().split())
gx -= 1
gy -= 1
S = [input() for _ in range(H)]

INF = 1 << 61
# 파이썬에서는 다차원 배열을 1차원으로 평평하게 만드는 것이 더 빠르다(여기서는 사용하지 않는다).
cost = [[INF] * W for _ in range(H)]

q = [] # queue는 list로 재현할 수 있다
# 정점에 방문하는 부분을 함수로 잘라내면 좋다 
def push(x: int, y: int, c: int):
    if S[x][y] == '#':
        return
    if cost[x][y] <= c:
        return
    cost[x][y] = c
    q.append((x, y))

# 너비 우선 탐색
push(sx, sy, 0)
for x, y in q:
    c2 = cost[x][y] + 1
    push(x - 1, y, c2)
    push(x, y - 1, c2)
    push(x + 1, y, c2)
    push(x, y + 1, c2)

print(cost[gx][gy])
