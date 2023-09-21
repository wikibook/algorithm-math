# 세그먼트 트리 (여기서는 책과 달리 pos가 0-indexed가 되도록 구현했다)
class segtree:
	# 요소 dat의 초기화를 수행한다(최초에는 전부 0)
	def __init__(self, n):
		self.size = 1
		while self.size < n:
			self.size *= 2
		self.dat = [ 0 ] * (self.size * 2)
	
	# 쿼리 1에 대한 처리
	def update(self, pos, x):
		pos += self.size # pos는 0-indexed이므로 A[pos]에만 해당되는 셀 번호는 pos + size
		self.dat[pos] = x
		while pos >= 2:
			pos //= 2
			self.dat[pos] = self.dat[pos * 2] + self.dat[pos * 2 + 1] # 8.8절에서 변경한 부분
	
	# 쿼리 2에 대한 처리
	# u는 현재의 셀 번호, [a, b)는 셀에 대응하는 반개구간, [l, r)은 구할 반개구간
	def query(self, l, r, a, b, u):
		if r <= a or b <= l:
			return 0 # 8.8절에서 변경한 부분
		if l <= a and b <= r:
			return self.dat[u]
		m = (a + b) // 2
		answerl = self.query(l, r, a, m, u * 2)
		answerr = self.query(l, r, m, b, u * 2 + 1)
		return answerl + answerr # 8.8절에서 변경한 부분

# 입력
N, Q = map(int, input().split())
queries = [ list(map(int, input().split())) for i in range(Q) ]

# 쿼리 처리
Z = segtree(N)
for q in queries:
	tp, *cont = q
	if tp == 1:
		pos, x = cont
		Z.update(pos - 1, x) # pos는 1-indexed로 입력되므로 update 함수의 인수는 pos - 1로 한다
	if tp == 2:
		l, r = cont
		answer = Z.query(l - 1, r - 1, 0, Z.size, 1) # 0-indexed 구현에서 첫 번째 셀에 해당하는 반개방 구간은 [0, size)이다
		print(answer)