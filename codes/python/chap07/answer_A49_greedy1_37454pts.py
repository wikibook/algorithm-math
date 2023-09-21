################################################
# 책 XXX페이지 전반부의 탐욕 알고리즘을 이용한 구현입니다.
################################################

# 입력
T = int(input())
P = [ None ] * T
Q = [ None ] * T
R = [ None ] * T
for i in range(T):
	P[i], Q[i], R[i] = map(int, input().split())
	P[i] -= 1 # 0 다시 시작
	Q[i] -= 1
	R[i] -= 1

# 배열 A 초기화
A = [ 0 ] * 20

# 탐욕 알고리즘
CurrentScore = 0
for i in range(T):
	# 패턴 A일 때의 점수 구하기
	ScoreA = CurrentScore
	PatA = [ 0 ] * 20
	for j in range(20):
		PatA[j] = A[j]
	PatA[P[i]] += 1
	PatA[Q[i]] += 1
	PatA[R[i]] += 1
	for j in range(20):
		if PatA[j] == 0:
			ScoreA += 1

	# 패턴 B일 때의 점수 구하기
	ScoreB = CurrentScore
	PatB = [ 0 ] * 20
	for j in range(20):
		PatB[j] = A[j]
	PatB[P[i]] -= 1
	PatB[Q[i]] -= 1
	PatB[R[i]] -= 1
	for j in range(20):
		if PatB[j] == 0:
			ScoreB += 1

	# 점수가 높은 쪽을 채택
	if ScoreA >= ScoreB:
		print("A")
		CurrentScore = ScoreA
		for j in range(20):
			A[j] = PatA[j]
	else:
		print("B")
		CurrentScore = ScoreB
		for j in range(20):
			A[j] = PatB[j]
