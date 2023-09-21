# 입력
N = int(input())
T = [ None ] * N
A = [ None ] * N
for i in range(N):
	T[i], A[i] = input().split()
	A[i] = int(A[i])

# 출력(Answer는 현재 칠판의 수)
Answer = 0
for i in range(N):
	if T[i] == '+':
		Answer += A[i]
	if T[i] == '-':
		Answer -= A[i]
	if T[i] == '*':
		Answer *= A[i]

	# 뺄셈의 답이 0 미만이 된 경우
	if Answer < 0:
		Answer += 10000

	# 여기에서 나머지를 구한다!
	Answer %= 10000
	print(Answer)
