# 입력
N, Q = map(int, input().split())
A = list(map(int, input().split()))
queries = [ list(map(int, input().split())) for i in range(Q) ]

# 사전 계산(여기서는 책과 달리 0-indexed로 구현했다)
LEVELS = 30
dp = [ [ None ] * N for i in range(LEVELS) ]
for i in range(0, N):
	dp[0][i] = A[i] - 1
for d in range(1, LEVELS):
	for i in range(0, N):
		dp[d][i] = dp[d - 1][dp[d - 1][i]]

# 쿼리 처리(여기서는 책과 달리 0-indexed로 구현했다)
for X, Y in queries:
	current_place = X - 1
	for d in range(29, -1, -1):
		if ((Y >> d) & 1) == 1:
			current_place = dp[d][current_place]
	print(current_place + 1) # current_place는 0-indexed로 계산했으므로 1을 더하여 출력한다

# 참고 1: 책의 C++ 프로그램에서 'Y의 2^d의 위치 찾기'는 C++에서는 (Y / (1 << d)) % 2로 구현되어 있었다.
# 파이썬에서도 19번째 줄은 (Y // (2 ** d)) % 2로 구현할 수 있지만, ((Y >> d) & 1)로 계산하는 것이 상수배 측면에서 더 빠르다.
# 참고 2: 이 프로그램의 평균 실행시간은 2초를 겨우 넘기는 정도이며, 제출에 따라서는 TLE가 될 수도 있습니다.
# 같은 프로그램을 PyPy3로 제출하면 0.5초 정도의 실행시간으로 AC 할 수 있다.