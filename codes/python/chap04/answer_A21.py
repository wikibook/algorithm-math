# 입력
N = int(input())
P = [ None ] * (N + 1)
A = [ None ] * (N + 1)
for i in range(1, N+1):
	P[i], A[i] = map(int, input().split())

# 동적 계획 알고리즘(LEN은 r-l의 값)
dp = [ [ None ] * (N + 1) for i in range(N + 1) ]
dp[1][N] = 0
for LEN in reversed(range(0, N-1)):
	for l in range(1, N-LEN+1):
		r = l + LEN

		# score1의 값(l-1번째의 블록을 제거했을 때의 득점)을 구한다
		score1 = 0
		if l>=2 and l<=P[l-1] and P[l-1]<=r:
			score1 = A[l-1]

		# score2의 값(r+1번째의 블록을 제거했을 때의 득점)을 구한다
		score2 = 0
		if r<=N-1 and l<=P[r+1] and P[r+1]<=r:
			score2 = A[r+1]

		# dp[l][r]을 구한다
		if l==1:
			dp[l][r] = dp[l][r+1] + score2
		elif r==N:
			dp[l][r] = dp[l-1][r] + score1
		else:
			dp[l][r] = max(dp[l-1][r] + score1, dp[l][r+1] + score2)

# 출력
Answer = 0
for i in range(1, N+1):
	Answer = max(Answer, dp[i][i])
print(Answer)
