# 입력(전반부)
H, W = map(int, input().split())
X = [ None ] * (H)
Z = [ [ 0 ] * (W + 1) for i in range(H + 1) ]
for i in range(H):
	X[i] = list(map(int, input().split()))

# 입력(후반부)
Q = int(input())
A = [ None ] * Q
B = [ None ] * Q
C = [ None ] * Q
D = [ None ] * Q
for i in range(Q):
	A[i], B[i], C[i], D[i] = map(int, input().split())

# 배열 Z는 이미 초기화됨
# 가로 방향으로 누적 합을 구한다
# X[i-1][j-1] 등으로 되어 있는 것은 배열이 0번부터 시작되기 때문입니다
for i in range(1, H+1):
	for j in range(1, W+1):
		Z[i][j] = Z[i][j-1] + X[i-1][j-1]

# 세로 방향으로 누적 합을 구한다
for j in range(1, W+1):
	for i in range(1, H+1):
		Z[i][j] = Z[i-1][j] + Z[i][j]

# 답을 구한다
for i in range(Q):
	print(Z[C[i]][D[i]] + Z[A[i]-1][B[i]-1] - Z[A[i]-1][D[i]] - Z[C[i]][B[i]-1])
