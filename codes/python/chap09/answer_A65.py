# 입력(A[2], ... , A[N]이 입력되는 값이 되도록 한다. , A[N]이 입력되는 값으로 설정)
N = int(input())
A = [ 0 ] * 2 + list(map(int, input().split()))

# 인접 리스트 생성
G = [ list() for i in range(N + 1) ]
for i in range(2, N + 1):
	G[A[i]].append(i) # 상사 → 부하직원 방향으로 방향 에지 추가

# 동적 계획 알고리즘(dp[x]는 직원 x의 부하직원 수)
dp = [ 0 ] * (N + 1)
for i in range(N, 0, -1):
	for j in G[i]:
		dp[i] += (dp[j] + 1)

# 답 (dp[1], dp[2], ... , dp[N])를 공백으로 구분하여 출력
print(*dp[1:])