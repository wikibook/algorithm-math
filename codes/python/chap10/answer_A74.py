# 입력
N = int(input())
P = [ list(map(int, input().split())) for i in range(N) ]

# "이전 수를 구하는 문제"를 2가지로 나눕니다.
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	for j in range(N):
		if P[i][j] != 0:
			X[i] = P[i][j]
			Y[j] = P[i][j]

# 역수를 구하는 관련 수
def inversion(A):
	answer = 0
	for i in range(len(A)):
		for j in range(i + 1, len(A)):
			if A[i] > A[j]:
				answer += 1
	return answer

# 답을 출력
print(inversion(X) + inversion(Y))