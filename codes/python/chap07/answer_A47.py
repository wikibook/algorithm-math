import random

# 2차원의 점을 다루는 클래스
class point2d:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	# 두 점 사이의 거리를 구하는 함수
	def dist(self, p):
		return ((self.x - p.x) ** 2 + (self.y - p.y) ** 2) ** 0.5

# 총 거리를 계산하는 함수
def get_score(n, points, P):
	score = 0
	for i in range(n):
		score += points[P[i]].dist(points[P[i + 1]])
	return score

# 등산 알고리즘으로 답을 구하는 함수 
# (여기서는 도시 번호를 0-indexed로 처리하고 있음에 유의)
def hill_climbing(n, points):
	# 초기 해 생성
	P = [ i % n for i in range(n + 1) ]
	current_score = get_score(n, points, P)
	# 등산 알고리즘
	NUM_LOOPS = 40000
	for t in range(NUM_LOOPS):
		# 반전시킬 구간 [L, R]을 선택
		l = random.randint(1, n - 1) # 1 이상 n-1 이하의 임의의 정수
		r = random.randint(1, n - 1) # 1 이상 n-1 이하의 임의의 정수
		if l > r:
			l, r = r, l
		# P[l], P[l+1], ..., P[r]를 역순으로
		P[l:r+1] = reversed(P[l:r+1])
		new_score = get_score(n, points, P)
		# 개선되면 점수를 업데이트, 악화되면 원래대로 되돌린다
		if current_score >= new_score:
			current_score = new_score
		else:
			P[l:r+1] = reversed(P[l:r+1])
	return P

# 입력
N = int(input())
points = [ None ] * N
for i in range(N):
	x, y = map(int, input().split())
	points[i] = point2d(x, y)

# 등산 알고리즘
answer = hill_climbing(N, points)

# 답을 출력(배열 answer의 요소는 0-indexed로 설정되어 있음에 주의)
for i in answer:
	print(i + 1)

# 주의 1: 이 프로그램을 Python으로 제출하면 등산 알고리즘의 루프를 7,000번 정도만 돌릴 수 있습니다,
# PyPy3로 제출하면 더 빠르게 동작하여 등산 알고리즘의 루프를 40,000회 정도 돌릴 수 있습니다.