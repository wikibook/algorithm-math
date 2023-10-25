# 입력
N = int(input())
H = list(map(int, input().split()))

# 동적계획법
dp = [ None ] * N
dp[0] = 0
for i in range(1, N):
	if i == 1:
		dp[i] = abs(H[i - 1] - H[i])
	if i >= 2:
		v1 = dp[i - 1] + abs(H[i - 1] - H[i])  # 1개 이전 발판에서 점프할 때
		v2 = dp[i - 2] + abs(H[i - 2] - H[i])  # 2개 이전 발판에서 점프할 때
		dp[i] = min(v1, v2)

# 답 출력
print(dp[N - 1])
