# 입력(배열 A는 0번부터 시작한다는 점에 유의!)
N, M = map(int, input().split())
A = [ None ] * M
for i in range(0, M):
	A[i] = list(map(int, input().split()))

# 배열 초기화
dp = [ [ 10 ** 9 ] * (2 ** N) for i in range(M + 1) ]

# 동적 계획 알고리즘
dp[0][0] = 0
for i in range(1, M+1):
	for j in range(0, 2 ** N):
		# already[k] = 1일 때, 물품 k는 이미 무료 상태다
		already = [ None ] * N
		for k in range(0, N):
			if (j // (2 ** k)) % 2 == 0:
				already[k] = 0
			else:
				already[k] = 1

		# 쿠폰 i를 선택한 경우의 정수 표현 v를 계산한다
		v = 0
		for k in range(0, N):
			if already[k] == 1 or A[i-1][k] == 1:
				v += (2 ** k)

		# 이동을 수행한다
		dp[i][j] = min(dp[i][j], dp[i-1][j])
		dp[i][v] = min(dp[i][v], dp[i-1][j] + 1)

# 출력
if dp[M][2 ** N - 1] == 1000000000:
	print("-1")
else:
	print(dp[M][2 ** N - 1])
