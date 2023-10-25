# 입력
N = int(input())

# 동적계획법
dp = [ None ] * (N + 1)
for i in range(N + 1):
	if i <= 1:
		dp[i] = 1
	else:
		dp[i] = dp[i - 1] + dp[i - 2]

# 답 출력
print(dp[N])
