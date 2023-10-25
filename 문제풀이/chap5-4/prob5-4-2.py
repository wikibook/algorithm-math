# 입력
H, W = map(int, input().split())
A = [[] for i in range(H)]
for i in range(H):
	A[i] = list(map(int, input().split()))

# 행의 총합 계산하기
gyou = [0 for i in range(H)]
for i in range(H):
	for j in range(W):
		gyou[i] += A[i][j]

# 열의 총합 계산하기
retu = [0 for i in range(W)]
for j in range(W):
	for i in range(H):
		retu[j] += A[i][j]

# 각 칸의 답 계산하기
Answer = [[0 for j in range(W)] for i in range(H)]
for i in range(H):
	for j in range(W):
		Answer[i][j] = gyou[i] + retu[j] - A[i][j]

# 출력
for i in range(H):
	print(*Answer[i])