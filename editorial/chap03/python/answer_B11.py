import bisect

# 입력
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
X = [ None ] * Q
for i in range(Q):
	X[i] = int(input())

# 배열 X 정렬
A.sort()

# 질문에 답한다(배열 A는 0번부터 시작한다는 점에 유의하세요!)
for i in range(Q):
	pos1 = bisect.bisect_left(A, X[i])
	print(pos1)
