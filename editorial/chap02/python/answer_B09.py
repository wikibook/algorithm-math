# 입력
N = int(input())
A = [ None ] * N
B = [ None ] * N
C = [ None ] * N
D = [ None ] * N
for i in range(N):
	A[i], B[i], C[i], D[i] = map(int, input().split())

# 각 용지에 대해 +1/-1을 더한다
T = [ [ 0 ] * 1501 for i in range(1501) ]
for i in range(N):
	T[A[i]][B[i]] += 1
	T[A[i]][D[i]] -= 1
	T[C[i]][B[i]] -= 1
	T[C[i]][D[i]] += 1

# 누적 합을 구한다
for i in range(0, 1501):
	for j in range(1, 1501):
		T[i][j] = T[i][j-1] + T[i][j]
for i in range(1, 1501):
	for j in range(0, 1501):
		T[i][j] = T[i-1][j] + T[i][j]

# 면적 계산
Answer = 0
for i in range(1501):
	for j in range(1501):
		if T[i][j] >= 1:
			Answer += 1

# 출력
print(Answer)
