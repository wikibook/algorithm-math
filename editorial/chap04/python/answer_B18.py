import sys

# 입력
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 동적 계획 알고리즘（i=0）
dp = [ [ None ] * (S + 1) for i in range(N + 1) ]
dp[0][0] = True
for i in range(1, S+1):
	dp[0][i] = False

# 동적 계획 알고리즘（i=1）
for i in range(1, N+1):
	for j in range(0,S+1):
		if j < A[i-1]:
			if dp[i-1][j] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False

		if j >= A[i-1]:
			if dp[i-1][j] == True or dp[i-1][j-A[i-1]] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False

# 선택이 존재하지 않는 경우
if dp[N][S] == False:
	print("-1")
	sys.exit(0)

# 답의 복원
Answer = []
Place = S
for i in reversed(range(1,N+1)):
	if dp[i-1][Place] == True:
		Place = Place - 0 # 카드 i를 선택하지 않음
	else:
		Place = Place - A[i-1] # 카드 i 선택
		Answer.append(i)
Answer.reverse()

# 답을 출력
Answer2 = [str(i) for i in Answer]
print(len(Answer))
print(" ".join(Answer2))
