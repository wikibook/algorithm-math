dp = [[0] * 300009 for _ in range(30)]
 
# 입력
N, K = map(int, input().split())

# 1 회 조작 후 값 구하기
for i in range(N + 1):
	dp[0][i] = i - sum(map(int, str(i)))

# 사전 계산
for d in range(29):
	for i in range(N + 1):
		dp[d + 1][i] = dp[d][dp[d][i]]

# 답을 구한다
for num in range(1, N + 1):
	for d in range(30):
		if K & (1 << d):
			num = dp[d][num]
	print(num)
