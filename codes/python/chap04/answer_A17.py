# 입력(A, B 가 0 번부터 시작한다는 점에 유의)
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 동적 계획 알고리즘
dp = [ None ] * (N+1)
dp[1] = 0
dp[2] = A[0]
for i in range(3, N+1):
	dp[i] = min(dp[i-1]+A[i-2], dp[i-2]+B[i-3])

# 답의 복원
# 변수 Place는 현재 위치(목표부터 진행한다)
# 예를 들어, 입력 예의 경우 Place는 5 → 4 → 2 → 1로 변화한다
Answer = []
Place = N
while True:
	Answer.append(Place)
	if Place == 1:
		break

	# 어디에서 방 Place로 이동하는 것이 최적인지 구한다
	if dp[Place-1] + A[Place-2] == dp[Place]:
		Place = Place - 1
	else:
		Place = Place - 2
Answer.reverse()

# 답을 출력
Answer2 = [str(i) for i in Answer]
print(len(Answer))
print(" ".join(Answer2))
