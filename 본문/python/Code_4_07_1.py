from copy import deepcopy

MOD = 1000000000

# 2×2 행렬 A, B의 곱을 리턴하는 함수
def multiply(A, B):
	global MOD
	C = [ [ 0, 0 ], [ 0, 0 ] ]
	for i in range(2):
		for j in range(2):
			for k in range(2):
				C[i][j] += A[i][k] * B[k][j]
				C[i][j] %= MOD
	return C

# A의 n제곱을 리턴하는 함수
def power(A, n):
	P = deepcopy(A)
	Q = [ [ 0, 0 ], [ 0, 0 ] ]
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
A = [ [ 1, 1 ], [ 1, 0 ] ]
B = power(A, N - 1)

# 답 계산 → 출력(아래에서 9번째 자리가 0이라면, 앞에 0을 포함하지 않는 형태로 출력하므로 주의)
answer = (B[1][0] + B[1][1]) % MOD
print(answer)
