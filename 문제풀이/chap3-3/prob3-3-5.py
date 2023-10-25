# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
x = 0
y = 0
z = 0
for i in range(N):
	if A[i] == 1:
		x += 1
	if A[i] == 2:
		y += 1
	if A[i] == 3:
		z += 1

# 출력
print(x * (x - 1) // 2 + y * (y - 1) // 2 + z * (z - 1) // 2)