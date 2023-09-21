# 입력
N, H, W = map(int, input().split())
A = [ None ] * N
B = [ None ] * N
for i in range(N):
	A[i], B[i] = map(int, input().split())

# 전부 XOR한 값(Nim sum)을 구한다
XOR_Sum = 0
for i in range(N):
	XOR_Sum = (XOR_Sum ^ (A[i]-1))
	XOR_Sum = (XOR_Sum ^ (B[i]-1))

# 출력
if XOR_Sum != 0:
	print("First")
else:
	print("Second")
