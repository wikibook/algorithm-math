import sys

# 깊이 우선 탐색을 하는 함수
def dfs(pos, G, visited):
	visited[pos] = True
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited)

# 재귀 호출 상한을 120000으로 설정
sys.setrecursionlimit(120000)

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
visited = [ False ] * (N + 1)
dfs(1, G, visited)

# 연결 판정(answer = true일 때 연결)
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")
