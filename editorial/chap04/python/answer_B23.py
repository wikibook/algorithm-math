# 입력
N = int(input())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 배열 dp 초기화
dp = [ [ 1000000000.0 ] * N for i in range(2 ** N) ]

# 동적 계획 알고리즘(dp[지나간 도시][현재 있는 도시]로 되어 있음)
dp[0][0] = 0
for i in range(2 ** N):
	for j in range(N):
		if dp[i][j] < 1000000000.0:

			# 도시 j에서 k로 이동하고 싶다!
			for k in range(N):
				if (i // (2 ** k)) % 2 == 0:
					DIST = ((1.0*(X[j]-X[k])* (X[j]-X[k]) + 1.0*(Y[j]-Y[k])*(Y[j]-Y[k])) ** 0.5)
					dp[i + (2 ** k)][k] = min(dp[i + (2 ** k)][k], dp[i][j] + DIST)

# 출력
print(dp[(2 ** N) - 1][0])
