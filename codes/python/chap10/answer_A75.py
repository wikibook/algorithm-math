# 입력
N = int(input())
problems = [ list(map(int, input().split())) for i in range(N) ] # Tuple (T[i], D[i])이 N 개씩 정렬된 배열이 된다.

# D[i]의 오름차순으로 정렬한다
problems.sort(key = lambda p: p[1])

# 동적 계획 알고리즘：사전 준비
MAX_D = max(map(lambda p: p[1], problems)) # D[i]의 최대값(책 속 코드에서는 '1440'이라는 상수를 사용하지만, 여기서는 MAX_D를 대신 사용하기로 한다)
dp = [ [ -(10 ** 10) ] * (MAX_D + 1) for i in range(N + 1) ]

# 동적 계획 알고리즘
dp[0][0] = 0
for i in range(N):
	t, d = problems[i] # 책 속의 T[i], D[i]에 대응
	for j in range(MAX_D + 1):
		if j > d or j < t:
			dp[i + 1][j] = dp[i][j]
		else:
			dp[i + 1][j] = max(dp[i][j], dp[i][j - t] + 1)

# 답을 출력
answer = max(dp[N])
print(answer)