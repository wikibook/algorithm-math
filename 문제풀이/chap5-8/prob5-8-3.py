import heapq

# 입력
N, M = map(int, input().split())
A, B, C = [ None ] * M, [ None ] * M, [ None ] * M
for i in range(M):
	A[i], B[i], C[i] = map(int, input().split())

# 인접리스트 작성 → 그래프 엣지 추가
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append((B[i], C[i]))
	G[B[i]].append((A[i], C[i]))

# 다익스트라 알고리즘: 배열 초기화 등
dist = [ 10 ** 19 ] * (N + 1)
used = [ False ] * (N + 1)
Q = list()
dist[1] = 0
heapq.heappush(Q, (0, 1))

# 다익스트라 알고리즘: 우선순위 큐 활용
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if used[pos] == True:
		continue
	used[pos] = True
	for i in G[pos]:
		to = i[0]
		cost = dist[pos] + i[1]
		if dist[to] > cost:
			dist[to] = cost
			heapq.heappush(Q, (dist[to], to))

# 답 출력
if dist[N] != 10 ** 19:
	print(dist[N])
else:
	print(-1)