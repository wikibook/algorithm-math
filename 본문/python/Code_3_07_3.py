# 입력
N, W = map(int, input().split())
w = [ None ] * N
v = [ None ] * N
for i in range(N):
	w[i], v[i] = map(int, input().split())

# 배열 초기화
INF = 10 ** 18
dp = [ [ None ] * (W + 1) for i in range(N + 1) ]
dp[0][0] = 0
for i in range(1, W + 1):
	dp[0][i] = -INF

# 동적계획법
for i in range(1, N + 1):
	for j in range(0, W + 1):
		if j < w[i - 1]:
			# j < w[i-1]라면, 방법A로 선택
			dp[i][j] = dp[i - 1][j]
		else:
			# j >= w[i-1]라면 방법A와 방법B 중에 큰 것으로 선택
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1])

# 답을 계산하고 출력
answer = max(dp[N])
print(answer)
