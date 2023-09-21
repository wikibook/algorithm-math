from collections import deque

# 입력(여기서는 책과 달리 램프의 번호가 0-indexed로 구현되어 있다)
N, M = map(int, input().split())
A = list(map(int, input().split()))
actions = [ list(map(lambda x: int(x) - 1, input().split())) for i in range(M) ] # 여기서는 X[i], Y[i], Z[i]를 0-indexed로 변환하여 받는다.

# 정점 pos의 상태에서 '램프 x, y, z의 상태'를 반전시켰을 때 정점 번호를 반환하는 함수
def get_next(pos, x, y, z):
	# pos의 2진법 표기법을 사용하여 정점 pos가 나타내는 램프의 상태 state를 계산합니다.
	# (pos 의 2^i 의 위치는 (pos // (2 ** i)) % 2 로 계산할 수 있음 → 1.4 절 참조)
	state = [ (pos // (2 ** i)) % 2 for i in range(N) ]
	# 램프 x, y, z 반전
	state[x] = 1 - state[x]
	state[y] = 1 - state[y]
	state[z] = 1 - state[z]
	# 램프의 상태 state를 가리키는 정점의 번호를 계산한다.
	#  (2진법을 10진법으로 변환하는 방법은 1.4절 참조)
	ret = 0
	for i in range(N):
		if state[i] == 1:
			ret += 2 ** i
	return ret

# 그래프에 에지를 추가
G = [ list() for i in range(2 ** N) ]
for i in range(2 ** N):
	for x, y, z in actions:
		nextstate = get_next(i, x, y, z)
		G[i].append(nextstate)

# 시작점, 목표점의 정점 번호를 결정한다.
start = 0
for i in range(N):
	if A[i] == 1:
		start += 2 ** i
goal = 2 ** N - 1

# 너비 우선 탐색 초기화
dist = [ -1 ] * (2 ** N)
dist[start] = 0
Q = deque()
Q.append(start)

# 너비 우선 탐색
while len(Q) >= 1:
	pos = Q.popleft() # 큐 Q의 첫 번째 요소를 제거하고 그 값을 pos에 대입
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.append(nex)

# 답을 출력
print(dist[goal])

# 주의 1: 이 문제에 대해서는 더 간결한 구현도 있습니다,
# 원한다면 answer_A70_extra.py도 참고해 주세요.