from collections import deque

# 입력
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 인접 리스트 생성
G = [ list() for i in range(N + 1) ]
for a, b in edges:
	G[a].append(b)
	G[b].append(a)

# 너비 우선 탐색의 초기화(dist[i] = ? 가 아닌 dist[i] = -1로 초기화됨을 주의)
dist = [ -1 ] * (N + 1)
dist[1] = 0
Q = deque()
Q.append(1)

# 너비 우선 탐색
while len(Q) >= 1:
	pos = Q.popleft() # 큐 Q의 첫 번째 요소를 제거하고 그 값을 pos에 대입
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.append(nex)

# 정점 1에서 각 정점까지의 최단 거리를 출력
for i in range(1, N + 1):
	print(dist[i])