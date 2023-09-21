# 입력
N, A, B = map(int, input().split())

# 배열 dp 정의
# dp[x]=True일 때 승리 상태, dp[x]=False일 때 패배 상태
dp = [ None ] * (N+1)

# 승자를 계산한다
for i in range(N+1):
	if i >= A and dp[i-A] == False:
		dp[i] = True
	elif i >= B and dp[i-B] == False:
		dp[i] = True
	else:
		dp[i] = False

# 출력
if dp[N] == True:
	print("First")
else:
	print("Second")
