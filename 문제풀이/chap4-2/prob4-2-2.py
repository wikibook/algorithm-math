# 입력
T = int(input())
N = int(input())
A = [0 for i in range(T + 2)]
B = [0 for i in range(T + 2)]
L = [0 for i in range(N)]
R = [0 for i in range(N)]
for i in range(N):
	L[i], R[i] = map(int, input().split())

# 계차 B[i] 계산하기
for i in range(N):
	B[L[i]] += 1
	B[R[i]] -= 1

# 누적합 A[i] 계산하기
A[0] = B[0]
for i in range(1, T):
	A[i] = A[i - 1] + B[i]

# 출력
for i in range(T):
	print(A[i])