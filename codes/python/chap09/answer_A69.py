# 최대 흐름을 위한 가장자리 구조체
class maxflow_edge:
	def __init__(self, to, cap, rev):
		self.to = to
		self.cap = cap
		self.rev = rev

# 깊이 우선 탐색
def dfs(pos, goal, F, G, used):
	if pos == goal:
		return F # 목표에 도착: 플로를 흘려보낼 수 있다! 
	# 탐색한다
	used[pos] = True
	for e in G[pos]:
		# 용량이 1 이상이고 아직 방문하지 않은 정점에만 이동한다
		if e.cap > 0 and not used[e.to]:
			flow = dfs(e.to, goal, min(F, e.cap), G, used)
			# 플로를 흘려보낼 수 있는 경우, 잔차 그래프의 용량을 flow만큼만 증가시킨다
			if flow >= 1:
				e.cap -= flow
				G[e.to][e.rev].cap += flow
				return flow
	# 모든 곳을 다 뒤져도 찾을 수 없는...
	return 0

# 노드 s에서 노드 t까지의 최대 플로의 총 유량을 반환한다(정점 수 N, 변의 목록 edges)
def maxflow(N, s, t, edges):
	# 초기 상태의 잔여 그래프 구축
	# (여기서는 책과 조금 다르게 구현했기 때문에 8번째 줄은 G[a]에 추가된 이후이므로 len(G[a]) - 1로 되어 있음에 주의)
	G = [ list() for i in range(N + 1) ]
	for a, b, c in edges:
		G[a].append(maxflow_edge(b, c, len(G[b])))
		G[b].append(maxflow_edge(a, 0, len(G[a]) - 1))
	INF = 10 ** 10
	total_flow = 0
	while True:
		used = [ False ] * (N + 1)
		F = dfs(s, t, INF, G, used)
		if F > 0:
			total_flow += F
		else:
			break # 흐름을 흘릴 수 없게 되면 작업 종료
	return total_flow

# 입력
N = int(input())
C = [ input() for i in range(N) ]

# 최대 유량을 구하고 싶은 그래프를 구축한다(에지의 요소는 (에지의 시작점 번호, 에지의 끝점 번호, 에지의 용량)의 튜플)
edges = []
for i in range(N):
	for j in range(N):
		if C[i][j] == '#':
			edges.append((i + 1, N + j + 1, 1))
for i in range(N):
	edges.append((2 * N + 1, i + 1, 1))     # 's → 파란색'의 에지
	edges.append((N + i + 1, 2 * N + 2, 1)) # '빨간색 → t'의 에지

# 해답을 찾아 출력
answer = maxflow(2 * N + 2, 2 * N + 1, 2 * N + 2, edges)
print(answer)