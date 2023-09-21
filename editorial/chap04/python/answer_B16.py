# 입력
N = int(input())
H = list(map(int, input().split()))

# 배열 준비
dp = [ None ] * N

# 동적 계획 알고리즘
dp[0] = 0
dp[1] = abs(H[0] - H[1])
for i in range(2, N):
	dp[i] = min(dp[i-1] + abs(H[i-1]-H[i]), dp[i-2] + abs(H[i-2]-H[i]))

# 출력
print(dp[N-1])
