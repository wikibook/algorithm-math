# 입력(A, B가 0번부터 시작하는 것에 주의)
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 배열 dp 초기화
dp = [ 2000000000 ] * N
dp[0] = 0

# 동적 계획 알고리즘
for i in range(N):
	if i <= N-2:
		dp[i+1] = min(dp[i+1], dp[i] + A[i])
	if i <= N-3:
		dp[i+2] = min(dp[i+2], dp[i] + B[i])

# 출력
print(dp[N-1])
