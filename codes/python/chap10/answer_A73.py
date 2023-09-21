import heapq

# 입력
N, M = map(int, input().split())
roads = [ list(map(int, input().split())) for i in range(M) ]

# 그래프 생성
G = [ list() for i in range(N + 1) ]
for a, b, c, d in roads:
	if d == 1:
		G[a].append((b, 10000 * c - 1))
		G[b].append((a, 10000 * c - 1))
	else:
		G[a].append((b, 10000 * c))
		G[b].append((a, 10000 * c))

# 데이크스트라 알고리즘(데이크스트라 알고리즘에 대한 자세한 설명은 본 서적의 9.4절 및 ... /chap09/answer_A64.py 참조)
INF = 10 ** 10
kakutei = [ False ] * (N + 1)
cur = [ INF ] * (N + 1)
cur[1] = 0
Q = []
heapq.heappush(Q, (cur[1], 1))
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if kakutei[pos] == True:
		continue
	kakutei[pos] = True
	for e in G[pos]:
		if cur[e[0]] > cur[pos] + e[1]:
			cur[e[0]] = cur[pos] + e[1]
			heapq.heappush(Q, (cur[e[0]], e[0]))

# 해답을 찾아 출력
# 마라톤 코스의 거리 : cur[N] / 10000을 소수점 이하로 반올림한 값
# 코스에 있는 나무의 개수 : cur[N]과 distance * 10000의 차분
distance = (cur[N] + 9999) // 10000
num_trees = distance * 10000 - cur[N]
print(distance, num_trees)