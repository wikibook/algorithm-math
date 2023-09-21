import math
import random

# 2차원 점을 다루는 클래스
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

# 담금질 기법으로 답을 구하는 함수
# (여기서는 도시 번호를 0-indexed로 처리하고 있음에 주의)
def simulated_annealing(n, points):
	# 초기 해 생성
	P = [ i % n for i in range(n + 1) ]
	current_score = get_score(n, points, P)
	# 담금질 기법
	NUM_LOOPS = 40000
	for t in range(NUM_LOOPS):
		# 반전시킬 구간 [L, R]을 선택한다
		l = random.randint(1, n - 1) # 1 이상 n-1 이하의 임의의 정수
		r = random.randint(1, n - 1) # 1 이상 n-1 이하의 임의의 정수
		if l > r:
			l, r = r, l
		# P[l], P[l+1], ... , P[r]을 역순으로 한다.
		P[l:r+1] = reversed(P[l:r+1])
		new_score = get_score(n, points, P)
		# 7.2절의 해답 예로부터 변경한 유일한 부분(Probability는 채용 확률)
		# (random.random()에서 0 이상 1 미만의 무작위 실수를 생성)
		T = 30 - 28 * (t / NUM_LOOPS)
		probability = math.exp(min((current_score - new_score) / T, 0))
		if random.random() < probability:
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

# 담금질 기법
answer = simulated_annealing(N, points)

# 답을 출력(배열 answer의 요소는 0-indexed로 되어 있음에 유의).
for i in answer:
	print(i + 1)

# 주의 1: 이 프로그램을 Python으로 제출하면 등산 알고리즘의 루프를 7,000번 정도만 돌릴 수 있습니다,
# PyPy3로 제출하면 더 빠르게 동작하여 등산 알고리즘의 루프를 40,000번 정도 돌릴 수 있습니다.
# 참고 2: 조금만 더 공들여 PyPy3에서 루프를 150,000번 정도 돌릴 수 있게 되어 점수 5000 이상도 기대할 수 있게 됩니다.