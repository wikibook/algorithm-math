import sys

# 깊이 우선 탐색을 하는 함수
def dfs(pos, G, color):
	for i in G[pos]:
		if color[i] == 0:
			# color[pos] = 1일 때 2, color[pos] = 2일 때 1
			color[i] = 3 - color[pos]
			dfs(i, G, color)

# 재귀 호출 깊이 상한을 210000으로 설정
sys.setrecursionlimit(210000)

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

# 깊이 우선 탐색
color = [ 0 ] * (N + 1)
for i in range(1, N + 1):
	if color[i] == 0:
		# 정점 i가 흰색인 경우(아직 방문하지 않은 연결 성분인 경우)
		color[i] = 1
		dfs(i, G, color)

# 이분 그래프인지 판정
answer = True
for i in range(M):
	if color[A[i]] == color[B[i]]:
		answer = False
if answer == True:
	print("Yes")
else:
	print("No")
