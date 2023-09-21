from collections import deque

# 입력 (여기서는 책과 달리 램프의 번호가 0-indexed로 구현되어 있다)
N, M = map(int, input().split())
A = list(map(int, input().split()))
actions = [ list(map(lambda x: int(x) - 1, input().split())) for i in range(M) ] # 여기서는 X[i], Y[i], Z[i]를 0-indexed로 변환하여 받는다

# 시작점, 목표점의 정점 번호를 결정한다
start = sum(A[i] * (2 ** i) for i in range(N))
goal = 2 ** N - 1

# 너비 우선 탐색 초기화
dist = [ -1 ] * (2 ** N)
dist[start] = 0
Q = deque()
Q.append(start)

# 너비 우선 탐색
# (여기서는 그래프를 실제로 가지고 있지 않고 POS에서 나오는 변을 그대로 계산하여 너비 우선 탐색을 합니다)
while len(Q) >= 1:
	pos = Q.popleft() # 큐 Q의 첫 번째 요소를 제거하고 그 값을 pos에 대입
	for x, y, z in actions:
		# 비트 연산의 XOR을 사용한다(XOR에 대해서는 칼럼 1 참조).
		# 램프 k를 반전하는 것은 정점 번호의 2^k 위치를 반전하는 것, 즉 2^k를 XOR하는 것과 같다.
		nex = pos ^ (1 << x) ^ (1 << y) ^ (1 << z)
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.append(nex)

# 답을 출력
print(dist[goal])

# 주의 1: 비트 연산은 곱셈(*), 나눗셈(//), 거듭제곱(**) 등의 연산에 비해 속도가 빠르기 때문이다,
# 이 프로그램은 answer_A70.py에 비해 약 1/5의 실행시간으로 답을 출력할 수 있다.