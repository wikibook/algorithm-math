# 입력
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 승자를 계산한다
# 배열 dp에 대해: dp[x]=true일 때 승리 상태, dp[x]=false일 때 패배 상태
dp = [ None ] * (N + 1)
for i in range(N+1):
	dp[i] = False
	for j in range(K):
		if i>=A[j] and dp[i-A[j]]==False:
			dp[i] = True # 패배 상태로 전환할 수 있다면, 승리 상태

# 출력
if dp[N] == True:
	print("First")
else:
	print("Second")
