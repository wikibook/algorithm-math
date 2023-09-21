# 입력
N = int(input())
H = list(map(int, input().split()))

# 배열 준비
dp = [ None ] * N

# 동적 계획 알고리즘
dp[0] = 0
dp[1] = abs(H[0] - H[1])
for i in range(2, N):
	dp[i] = min(dp[i-1] + abs(H[i-1]-H[i]), dp[i-2] + abs(H[i-2]-H[i]))

# 답의 복원
# 변수 Place는 현재 위치(목표부터 진행한다)
Answer = []
Place = N-1
while True:
	Answer.append(Place + 1)
	if Place == 0:
		break

	# 어디에서 방 Place로 이동하는 것이 최적인지 구한다
	if dp[Place-1] + abs(H[Place-1]-H[Place]) == dp[Place]:
		Place = Place - 1
	else:
		Place = Place - 2
Answer.reverse()

# 답을 출력
Answer2 = [str(i) for i in Answer]
print(len(Answer))
print(" ".join(Answer2))
