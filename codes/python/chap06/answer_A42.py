# 정수의 쌍(a, b)가 결정되었을 때 참가 가능한 학생 수를 반환하는 함수
def GetScore(a, b, A, B, K):
	cnt = 0
	for i in range(N):
		if a <= A[i] and A[i] <= a + K and b <= B[i] and B[i] <= b+K:
			cnt += 1
	return cnt

# 입력
N, K = map(int, input().split())
A = [ None ] * N
B = [ None ] * N
for i in range(N):
	A[i], B[i] = map(int, input().split())

# (a, b)쌍을 완전 탐색
Answer = 0
for a in range(1, 101):
	for b in range(1, 101):
		Score = GetScore(a, b, A, B, K)
		Answer = max(Answer, Score)

# 출력
print(Answer)
