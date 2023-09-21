import copy

# 1회의 연산 (P[i], Q[i], R[i])을 표현하는 구조체
class round:
	def __init__(self, p, q, r):
		self.p = p
		self.q = q
		self.r = r

# 상태를 나타내는 구조체
class state:
	# 보드 상태 초기화
	def __init__(self, n):
		self.score = 0      # 잠정 점수
		self.x = [ 0 ] * n  # 현재 배열 X의 값
		self.lastmove = '?' # 마지막 이동 ('A' 또는 'B', 단, 초기 상태에서는 '?' 로 설정)
		self.lastpos = -1   # Beam[i-1][어디]에서 전환한 내용(단, 초기 상태에서는 -1로 설정해둠)

# 빔 서치를 수행하는 함수
def beam_search(N, T, rounds):
	# 2차원 배열 빔을 준비하여 0번째 수의 상태를 설정
	WIDTH = 10000
	beam = [ list() for i in range(T + 1) ]
	beam[0].append(state(N))

	# 빔 서치
	for i in range(T):
		candidate = list()
		for j in range(len(beam[i])):
			# 조작 A인 경우
			sousa_a = copy.deepcopy(beam[i][j])
			sousa_a.lastmove = 'A'
			sousa_a.lastpos = j
			sousa_a.x[rounds[i].p] += 1
			sousa_a.x[rounds[i].q] += 1
			sousa_a.x[rounds[i].r] += 1
			sousa_a.score += sousa_a.x.count(0) # 점수에 'sousa_a.x에 포함된 0의 개수'를 더한다
			# 조작 B인 경우
			sousa_b = copy.deepcopy(beam[i][j])
			sousa_b.lastmove = 'B'
			sousa_b.lastpos = j
			sousa_b.x[rounds[i].p] -= 1
			sousa_b.x[rounds[i].q] -= 1
			sousa_b.x[rounds[i].r] -= 1
			sousa_b.score += sousa_b.x.count(0) # 점수에 'sousa_a.x에 포함된 0의 개수'를 더한다
			# 후보에 추가
			candidate.append(sousa_a)
			candidate.append(sousa_b)
		# 정렬하여 beam[i+1] 결과 계산하기
		candidate.sort(key = lambda s: -s.score)
		beam[i + 1] = copy.deepcopy(candidate[:WIDTH]) #  candidate의 상위 WIDTH 건만 기록한다
  
	# 빔 서치 복원
	current_place = 0
	answer = [ None ] * T
	for i in range(T, 0, -1):
		answer[i - 1] = beam[i][current_place].lastmove
		current_place = beam[i][current_place].lastpos
	return answer


# 입력
T = int(input())
rounds = [ None ] * T
for i in range(T):
	p, q, r = map(int, input().split())
	rounds[i] = round(p - 1, q - 1, r - 1) # 책과 달리 여기서는 0-indexed로 만들기 위해 1을 빼고 있다

# 빔 서치를 수행하여 답을 구한다(책과 달리 빔 서치 복원은 함수 내에서 수행)
answer = beam_search(20, T, rounds)

# 출력
for c in answer:
	print(c)

# 주의 1: 이 프로그램은 Python으로 제출하면 빔폭 200 정도, PyPy3로 제출하면 빔폭 350 정도로 실행시간 제한인 1초를 넘지 않는다.
# 주의 2: 여기서는 deepcopy 함수를 사용하고 있는데, 이것이 실행 속도를 느리게 하는 원인이 되고 있습니다.
# 이 함수를 사용하지 않고 구현하면 프로그램이 더 빨라지고, 빔폭을 더 크게 만들 수 있습니다. 생각해 봅시다.