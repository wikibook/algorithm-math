from copy import deepcopy

MOD = 1000000007

# K=2때의 전환
Mat2 = [
	[0, 0, 0, 1],
	[0, 0, 1, 0],
	[0, 1, 0, 0],
	[1, 0, 0, 1]
]
 
# K=3때의 전환
Mat3 = [
	[0, 0, 0, 0, 0, 0, 0, 1],
	[0, 0, 0, 0, 0, 0, 1, 0],
	[0, 0, 0, 0, 0, 1, 0, 0],
	[0, 0, 0, 0, 1, 0, 0, 1],
	[0, 0, 0, 1, 0, 0, 0, 0],
	[0, 0, 1, 0, 0, 0, 0, 0],
	[0, 1, 0, 0, 0, 0, 0, 1],
	[1, 0, 0, 1, 0, 0, 1, 0]
]
 
# K=4때의 전환
Mat4 = [
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
	[0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0],
	[0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
	[0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
	[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
	[0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0],
	[1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1]
]

# 3×3 행렬 A, B의 곱을 리턴하는 함수
def multiply(A, B, size_):
	global MOD
	C = [ [ 0 ] * size_ for i in range(size_) ]
	for i in range(size_):
		for j in range(size_):
			for k in range(size_):
				C[i][j] += A[i][k] * B[k][j]
				C[i][j] %= MOD
	return C

# A의 n제곱을 리턴하는 함수
def power(A, n, size_):
	P = deepcopy(A)
	Q = [ [ 0 ] * size_ for i in range(size_) ]
	flag = False
	for i in range(60):
		if (n & (1 << i)) != 0:
			if flag == False:
				Q = deepcopy(P)
				flag = True
			else:
				Q = deepcopy(multiply(Q, P, size_))
		P = deepcopy(multiply(P, P, size_))
	return Q

# 입력
K, N = map(int, input().split())

# 행렬A 만들기
A = [ [ 0 ] * (1 << K) for i in range(1 << K) ]
for i in range(1 << K):
	for j in range(1 << K):
		if K == 2:
			A[i][j] = Mat2[i][j]
		if K == 3:
			A[i][j] = Mat3[i][j]
		if K == 4:
			A[i][j] = Mat4[i][j]

# B = A^N 계산
B = power(A, N, (1 << K))

# 답 출력
print(B[(1 << K) - 1][(1 << K) - 1])