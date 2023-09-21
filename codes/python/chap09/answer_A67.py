# Union-Find 나무
class unionfind:
	# n개의 정점으로 구성된 Union-Find 트리를 생성한다.
	# (여기서는 정점 번호가 1-indexed가 되도록 구현했지만, 0-indexed인 경우 par, size의 크기는 n으로 하면 된다)
	def __init__(self, n):
		self.n = n
		self.par = [ -1 ] * (n + 1) # 최초에는 부모가 없다
		self.size = [ 1 ] * (n + 1) # 최초에는 그룹의 노드 수가 1
	
	# 노드 x의 루트를 반환하는 함수
	def root(self, x):
		# 1개 앞(부모)이 없어질 때까지(즉, 루트에 도달할 때까지) 1개 앞(부모)으로 계속 이동한다.
		while self.par[x] != -1:
			x = self.par[x]
		return x
	
	# 요소 u, v를 통합하는 함수
	def unite(self, u, v):
		rootu = self.root(u)
		rootv = self.root(v)
		if rootu != rootv:
			# u와 v가 서로 다른 그룹일 때만 처리한다
			if self.size[rootu] < self.size[rootv]:
				self.par[rootu] = rootv
				self.size[rootv] += self.size[rootu]
			else:
				self.par[rootv] = rootu
				self.size[rootu] += self.size[rootv]
	
	# 요소 u와 v가 같은 그룹인지 반환하는 함수
	def same(self, u, v):
		return self.root(u) == self.root(v)

# 입력
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 에지를 길이의 오름차순으로 정렬한다
edges.sort(key = lambda x: x[2])

# 최소 전역 트리를 구한다
uf = unionfind(N)
answer = 0
for a, b, c in edges:
	if not uf.same(a, b):
		uf.unite(a, b)
		answer += c

# 답 출력
print(answer)