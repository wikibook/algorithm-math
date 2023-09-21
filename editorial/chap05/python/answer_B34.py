# 입력
N, X, Y = map(int, input().split())
A = list(map(int, input().split()))

# Grundy 수 계산
XOR_Sum = 0
for i in range(N):
	Grundy = [0, 0, 1, 1, 2] # 5로 나눈 나머지 Grundy 수에 대응하는 Grundy 수
	XOR_Sum ^= Grundy[A[i] % 5]

# 출력
if XOR_Sum != 0:
	print("First")
else:
	print("Second")
