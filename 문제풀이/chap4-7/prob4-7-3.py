from copy import deepcopy

MOD = 1000000007

# 3×3 행렬 A, B의 곱을 리턴하는 함수
def multiply(A, B):
	global MOD
	C = [ [ 0, 0, 0 ], [ 0, 0, 0 ], [ 0, 0, 0 ] ]
	for i in range(3):
		for j in range(3):
			for k in range(3):
				C[i][j] += A[i][k] * B[k][j]
				C[i][j] %= MOD
	return C

# A의 n제곱을 리턴하는 함수
def power(A, n):
	P = deepcopy(A)
	Q = [ [ 0, 0, 0 ], [ 0, 0, 0 ], [ 0, 0, 0 ] ]
	flag = False
	for i in range(60):
		if (n & (1 << i)) != 0:
			if flag == False:
				Q = deepcopy(P)
				flag = True
			else:
				Q = deepcopy(multiply(Q, P))
		P = deepcopy(multiply(P, P))
	return Q

# 입력 → 거듭 제곱 계산(N이 2 이상이 아니라면 제대로 작동하지 않으므로 주의)
N = int(input())
A = [ [ 1, 1, 1 ], [ 1, 0, 0 ], [ 0, 1, 0 ] ]
B = power(A, N - 1)

# 답 계산
answer = (2 * B[2][0] + B[2][1] + B[2][2]) % MOD
print(answer)