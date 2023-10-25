# 입력
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 배열 초기화
dp = [ [ None ] * (S + 1) for i in range(N + 1) ]
dp[0][0] = True
for i in range(1, S + 1):
	dp[0][i] = False

# 동적계획법
for i in range(1, N + 1):
	for j in range(0, S + 1):
		if j < A[i - 1]:
			# j < A[i-1]라면, 카드 i를 선택할 수 없음
			dp[i][j] = dp[i - 1][j]
		else:
			# j >= A[i-1]라면, 선택/선택하지 않음이라는 선택지가 있음
			if (dp[i - 1][j] == True or dp[i - 1][j - A[i - 1]] == True):
				dp[i][j] = True
			else:
				dp[i][j] = False

# 답 출력
if dp[N][S] == True:
	print("Yes")
else:
	print("No")