# 입력
N, X, Y = map(int, input().split())
A = list(map(int, input().split()))

# Grundy 수치를 구하다
# 변수 grundy[i]: 돌이 i개일 때의 Grundy 수
# 변수 Transit[i]: Grundy 수가 i가 되도록 전이할 수 있는가
grundy = [ None ] * 100001
for i in range(100001):
	Transit = [False, False, False]
	if i >= X:
		Transit[grundy[i-X]] = True
	if i >= Y:
		Transit[grundy[i-Y]] = True

	if Transit[0] == False:
		grundy[i] = 0
	elif Transit[1] == False:
		grundy[i] = 1
	else:
		grundy[i] = 2

# 출력
XOR_Sum = 0
for i in range(N):
	XOR_Sum = (XOR_Sum ^ grundy[A[i]])
if XOR_Sum >= 1:
	print("First")
else:
	print("Second")
