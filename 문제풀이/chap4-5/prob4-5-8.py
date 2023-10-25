import heapq

# 입력
K = int(input())

# 인접리스트 작성 → 그래프 엣지 추가
G = [ list() for i in range(K) ]
for i in range(K):
	for j in range(10):
		if i == 0 and j == 0:
			continue
		G[i].append(((i * 10 + j) % K, j))

# 다익스트라 알고리즘: 배열 초기화 등
dist = [ 10 ** 10 ] * K
used = [ False ] * K
Q = list()
heapq.heappush(Q, (0, 0))  # 여기에서 dist[0] = 0로는 되지 않으므로 주의

# 다익스트라 알고리즘: 우선순위 큐 활용
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if used[pos] == True:
		continue
	used[pos] = True
	for i in G[pos]:
		to = i[0]
		cost = dist[pos] + i[1]
		if pos == 0:
			cost = i[1]  # 정점 0의 경우는 제외
		if dist[to] > cost:
			dist[to] = cost
			heapq.heappush(Q, (dist[to], to))

# 답 출력
print(dist[0])
