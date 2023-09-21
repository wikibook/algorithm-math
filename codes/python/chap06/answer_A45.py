# 입력
N, C = input().split()
A = input()
N = int(N)

# 점수 계산
score = 0
for i in range(N):
	if A[i] == 'W':
		score += 0
	if A[i] == 'B':
		score += 1
	if A[i] == 'R':
		score += 2

# 출력
if score%3 == 0 and C == 'W':
	print("Yes")
elif score%3 == 1 and C == 'B':
	print("Yes")
elif score%3 == 2 and C == 'R':
	print("Yes")
else:
	print("No")
