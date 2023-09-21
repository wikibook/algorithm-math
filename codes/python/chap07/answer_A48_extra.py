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
	NUM_LOOPS = 150000
	for t in range(NUM_LOOPS):
		# 반전시킬 구간 [L, R]을 선택한다
		l = random.randint(1, n - 1) # 1 이상 n-1 이하의 임의의 정수
		r = random.randint(1, n - 1) # 1 이상 n-1 이하의 임의의 정수
		if l > r:
			l, r = r, l
		# P[l], P[l+1], ... , P[r]을 역순으로 했을 때의 총 거리 new_score를 구한다.
		#  (현재 총거리와의 차이를 고려한다)
		new_score = current_score
		new_score -= points[P[l - 1]].dist(points[P[l]])
		new_score -= points[P[r]].dist(points[P[r + 1]])
		new_score += points[P[l - 1]].dist(points[P[r]])
		new_score += points[P[l]].dist(points[P[r + 1]])
		# 7.2절의 해답 예로부터 변경한 유일한 부분(Probability는 채용 확률)
		# (random.random() 으로 0 이상 1 미만의 무작위 실수 생성)
		T = 30 - 28 * (t / NUM_LOOPS)
		probability = math.exp(min((current_score - new_score) / T, 0))
		if random.random() < probability:
			# 해답이 개선되었을 때만 P를 갱신한다
			P[l:r+1] = reversed(P[l:r+1])
			current_score = new_score
	return P

# 입력
N = int(input())
points = [ None ] * N
for i in range(N):
	x, y = map(int, input().split())
	points[i] = point2d(x, y)

# 담금질 기법
answer = simulated_annealing(N, points)

# 답을 출력(배열 answer의 요소는 0-indexed로 되어 있음에 유의)
for i in answer:
	print(i + 1)

# 주의 1: 이 프로그램을 PyPy3로 제출하면 루프를 150,000번 정도 돌릴 수 있다. 이는 answer_A48.py에 비해 약 4배 정도 더 많은 횟수입니다.
# 휴리스틱 문제에서는 실행 속도를 개선하면 점수나 순위가 크게 올라가는 경우가 많습니다.
# 주의 2: 이 프로그램이 빠른 이유는 해답이 실제로 개선될 때까지 P의 구간을 실제로 뒤집지 않고, 그 차이에 따라 new_score를 추정하기 때문이다,
# 해의 개선이 없을 때의 1회 루프 계산량이 O(1)이 되기 때문이다.