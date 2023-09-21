import heapq

# 입력
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 인접 리스트 생성(가중치 있는 그래프이므로 각 변에 대해 (인접 정점, 가중치)의 튜플을 기록)
G = [ list() for i in range(N + 1) ]
for a, b, c in edges:
	G[a].append((b, c))
	G[b].append((a, c))

# 배열 큐 초기화(큐에 (거리, 정점 번호) 튜플을 기록)
INF = 10 ** 10
kakutei = [ False ] * (N + 1)
cur = [ INF ] * (N + 1)
cur[1] = 0
Q = []
heapq.heappush(Q, (cur[1], 1))

# 데이크스트라 알고리즘
while len(Q) >= 1:
	# 다음에 확정할 노드를 구한다
	# (여기서는 우선순위 큐 Q의 가장 작은 요소를 제거하고 그 요소의 두 번째 값(정점 번호)을 pos에 대입한다.)
	pos = heapq.heappop(Q)[1]

	# Q의 최소 요소가 '이미 확정한 노드'인 경우
	if kakutei[pos] == True:
		continue
	
	# cur[x] 값을 업데이트한다
	kakutei[pos] = True
	for e in G[pos]:
		# 책 속 코드와 pos = e[0], cost = e[1]로 대응한다.
		if cur[e[0]] > cur[pos] + e[1]:
			cur[e[0]] = cur[pos] + e[1]
			heapq.heappush(Q, (cur[e[0]], e[0]))

# 답을 출력
for i in range(1, N + 1):
	if cur[i] != INF:
		print(cur[i])
	else:
		print("-1")