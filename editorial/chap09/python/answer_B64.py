from heapq import heappush, heappop

N, M = map(int, input().split())
g = [[] for _ in range(N)]
for _ in range(M):
    A, B, C = map(int, input().split())
    A -= 1
    B -= 1
    g[A].append((B, C))
    g[B].append((A, C))

INF = 1 << 61
cost = [INF] * N
back = [-1] * N
q = []

# 정점에 도달하는 부분을 함수로 잘라내기
def push(prev: int, i: int, c: int):
    if cost[i] <= c:
        return
    cost[i] = c
    back[i] = prev
    heappush(q, (c, i))

# 복원의 편의를 위해 뒤에서 Dijkstra 방법
push(-1, N - 1, 0)
while q:
    c, x = heappop(q)
    if cost[x] != c:
        continue # 같은 정점에서 여러 번 탐색하지 않음 (최악의 Θ(N^2) 시간 소요)
    for j, d in g[x]:
        push(x, j, c + d)

# 최단 경로 복원
ans = [0]
while ans[-1] != N - 1:
    ans.append(back[ans[-1]])

for x in ans:
    print(x + 1)