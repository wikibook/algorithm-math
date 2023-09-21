INF = 1 << 61
class Edge:
    def __init__(self, to, cap, rev):
        self.to = to
        self.cap = cap
        self.rev = rev

class FordFulkerson:
    def __init__(self, N):
        self.size = N
        self.g = [[] for _ in range(N)]

    def add_edge(self, a, b, c):
        g = self.g
        e = Edge(b, c, None)
        rev = Edge(a, 0, e)
        e.rev = rev
        g[a].append(e)
        g[b].append(rev)

    def dfs(self, i, goal, F):
        # 목표에 도착
        if i == goal:
            return F

        self.visited[i] = True

        for e in self.g[i]:
            # 용량 0인 에지는 사용할 수 없다
            if e.cap == 0:
                continue
            # 이미 방문한 정점에 가지 않는다
            if self.visited[e.to]:
                continue
            # 목적지까지의 패스를 찾는다
            flow = self.dfs(e.to, goal, min(F, e.cap))
            # 플로를 흘려보낼 수 있는 경우, 잔차 그래프의 용량을 flow만큼만 증가시킨다
            if flow:
                e.cap -= flow
                e.rev.cap += flow
                return flow
        # 구석구석을 뒤져도 찾지 못했다
        return 0

    def max_flow(self, s, t):
        ans = 0
        while True:
            self.visited = [False] * self.size
            F = self.dfs(s, t, INF)

            # 플로를 흘려보낼 수 없다면 조작 종료
            if F == 0:
                break
            ans += F
        return ans

N, M = map(int, input().split())
P = list(map(int, input().split()))

# 그래프 구축
S = N
T = N + 1
g = FordFulkerson(T + 1)
offset = 0
for i in range(N):
    if P[i] >= 0:
        # 특급역으로 만들지 않을 경우의 비용
        offset += P[i]
        g.add_edge(S, i, P[i])
    else:
        # 특급역으로 만들 경우의 비용
        g.add_edge(i, T, -P[i])

for _ in range(M):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    g.add_edge(A, B, INF)

print(offset - g.max_flow(S, T))
