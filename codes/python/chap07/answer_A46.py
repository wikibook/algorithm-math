# 2차원의 점을 다루는 클래스
class point2d:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	# 두 점 사이의 거리를 구하는 함수
	def dist(self, p):
		return ((self.x - p.x) ** 2 + (self.y - p.y) ** 2) ** 0.5

# 탐욕 알고리즘을 사용해 답을 구하는 함수
# (여기서는 도시 번호를 0-indexed로 처리하고 있음에 유의)
def play_greedy(n, points):
	# 배열 등 초기화
	current_place = 0
	visited = [ False ] * n
	visited[0] = True
	P = [ 0 ]
	# 탐욕 알고리즘 시작
	for i in range(1, n):
		mindist = 10 ** 10 # 현 시점에서의 거리의 최소
		min_id = -1 # 다음에는 어떤 도시로 이동해야 할까?
		# 거리가 최소가 되는 도시를 찾는다
		for j in range(n):
			if not visited[j] and mindist > points[current_place].dist(points[j]):
				mindist = points[current_place].dist(points[j])
				min_id = j
		# 현재 위치 업데이트
		visited[min_id] = True
		P.append(min_id)
		current_place = min_id
	# 최후에 방문하는 도시
	P.append(0)
	return P

# 입력
N = int(input())
points = [ None ] * N
for i in range(N):
	x, y = map(int, input().split())
	points[i] = point2d(x, y)

# 탐욕 알고리즘
answer = play_greedy(N, points)

# 답을 출력(배열 answer의 요소는 0-indexed로 설정되어 있음에 주의)
for i in answer:
	print(i + 1)