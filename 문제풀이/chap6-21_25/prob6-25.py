import sys

# 깊이 우선 탐색을 하는 함수
def dfs(pos, G, visited, dp):
	visited[pos] = True
	dp[pos] = 1
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited, dp)
			dp[pos] += dp[i]

# 재귀 호출 상한을 120000으로 설정
sys.setrecursionlimit(120000)

# 입력
N = int(input())
A = [ None ] * (N - 1)
B = [ None ] * (N - 1)
for i in range(N - 1):
	A[i], B[i] = map(int, input().split())

# 인접리스트 작성
G = [ list() for i in range(N + 1) ]
for i in range(N - 1):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 깊이 우선 탐색 (DFS)를 사용한 동적계획법
visited = [ False ] * (N + 1)
dp = [ None ] * (N + 1)
dfs(1, G, visited, dp)

# 답을 계산하고 출력
answer = 0
for i in range(2, N + 1):
	answer += dp[i] * (N - dp[i])
print(answer)