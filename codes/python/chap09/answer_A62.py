import sys

# 재귀 호출의 깊이 제한을 120000으로 설정한다.
sys.setrecursionlimit(120000)

# 깊이 우선 탐색을 수행하는 함수(pos는 현재 위치, visited[x]는 정점 x가 파란색인지 아닌지를 나타내는 진위값)
def dfs(pos, G, visited):
	visited[pos] = True
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited)

# 입력
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 인접 리스트 생성
G = [ list() for i in range(N + 1) ] # G[i]는 버텍스 i에 인접한 버텍스의 목록
for a, b in edges:
	G[a].append(b) # 정점 a 에 인접한 정점으로 b 를 추가한다.
	G[b].append(a) # 정점 b 에 인접한 정점으로 a 를 추가한다.

# 깊이 우선 탐색
visited = [ False ] * (N + 1)
dfs(1, G, visited)

# 연결 여부 판단(answer = true인 경우 연결)
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False

# 답 출력
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")