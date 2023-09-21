# 입력
N = int(input())
A = list(map(int, input().split()))

# 전부 XOR한 값(Nim sum)을 구한다
XOR_Sum = A[0]
for i in range(1,N):
	XOR_Sum = (XOR_Sum ^ A[i])

# 출력
if XOR_Sum >= 1:
	print("First")
else:
	print("Second")
