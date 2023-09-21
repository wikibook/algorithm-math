# 입력(배열 A, B는 0번부터 시작한다는 점에 주의!)
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 배열 초기화
dp = [ -(10 ** 9) ] * (N + 1)
dp[1] = 0

# 동적 계획 알고리즘
for i in range(1, N):
	dp[A[i-1]] = max(dp[A[i-1]], dp[i] + 100)
	dp[B[i-1]] = max(dp[B[i-1]], dp[i] + 150)

# 출력
print(dp[N])
