import queue

# 입력
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 인접리스트 작성
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 너비 우선 탐색 초기화(dist[i] = -1일 때 아직 도달하지 않은 흰색 정점으로 취급)
dist = [ -1 ] * (N + 1)
Q = queue.Queue()
dist[1] = 0
Q.put(1) # Q에 1을 추가(조작1)

# 너비 우선 탐색
while not Q.empty():
	pos = Q.get() # Q의 앞을 확인하고, 이를 꺼냄(조작2, 3)
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.put(nex) # Q에 nex를 추가(조작1)

# 정점1에서 각 정점까지의 최단 거리를 출력
for i in range(1, N + 1):
	print(dist[i])
