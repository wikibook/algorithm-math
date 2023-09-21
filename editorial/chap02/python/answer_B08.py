# 입력(전반부)
N = int(input())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 입력(후반부)
Q = int(input())
A = [ None ] * Q
B = [ None ] * Q
C = [ None ] * Q
D = [ None ] * Q
for i in range(Q):
	A[i], B[i], C[i], D[i] = map(int, input().split())

# 각 좌표에 있는 점의 개수를 세어본다
S = [ [ 0 ] * 1501 for i in range(1501) ]
for i in range(N):
	S[X[i]][Y[i]] += 1

# 누적 합을 구한다
T = [ [ 0 ] * 1501 for i in range(1501) ]
for i in range(1, 1501):
	for j in range(1, 1501):
		T[i][j] = T[i][j-1] + S[i][j]
for j in range(1, 1501):
	for i in range(1, 1501):
		T[i][j] = T[i-1][j] + T[i][j]

# 답을 구한다
for i in range(Q):
	print(T[C[i]][D[i]] + T[A[i] - 1][B[i] - 1] - T[A[i] - 1][D[i]] - T[C[i]][B[i] - 1])
