# 이 프로그램은 c[i-1][j-1]이 칸 (i, j)를 나타내게 구현했습니다.
# 칸 (i, j)의 정점 번호는 i * W + j가 되며, 정점 번호 0, 1, 2, ..., HW-1까지 존재합니다.

import queue

# 입력
H, W = map(int, input().split())
sx, sy = map(int, input().split())
gx, gy = map(int, input().split())
c = [ input() for i in range(H) ]
start = (sx - 1) * W + (sy - 1)
goal = (gx - 1) * W + (gy - 1)

# 인접리스트 작성
G = [ list() for i in range(H * W) ]

# 가로 방향 엣지 [(i, j) - (i, j+1)]를 그래프에 추가
for i in range(H):
	for j in range(W - 1):
		if c[i][j] == "." and c[i][j + 1] == ".":
			idx1 = i * W + j  # (i, j)의 정점 번호
			idx2 = i * W + (j + 1)  # (i, j + 1)의 정점 번호
			G[idx1].append(idx2)
			G[idx2].append(idx1)

# 세로 방향 엣지 [(i, j) - (i+1, j)]를 그래프에 추가
for i in range(H - 1):
	for j in range(W):
		if c[i][j] == "." and c[i + 1][j] == ".":
			idx1 = i * W + j  # (i, j)의 정점 번호
			idx2 = (i + 1) * W + j  # (i + 1, j)의 정점 번호
			G[idx1].append(idx2)
			G[idx2].append(idx1)

# 너비 우선 탐색 초기화(dist[i] = -1일 때 아직 도달하지 않은 흰색 정점으로 취급)
dist = [ -1 ] * (H * W)
Q = queue.Queue()
dist[start] = 0
Q.put(start) # Q에 start를 추가

# 너비 우선 탐색
while not Q.empty():
	pos = Q.get() # Q의 가장 앞을 확인하고, 이를 추출합니다.
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.put(nex) # Q에 nex를 추가

# 답 출력
print(dist[goal])
