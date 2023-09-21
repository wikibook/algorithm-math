import bisect

# 배열 A의 가장 긴 증가부 분절(LIS)의 길이를 계산한다
# 배열 dp를 사용하지 않는 구현방법을 이용하고 있다
def Get_LISvalue(A):
	LEN = 0
	L = []
	for i in range(N):
		pos = bisect.bisect_left(L, A[i])
		if pos == LEN:
			L.append(A[i])
			LEN += 1
		else:
			L[pos] = A[i]
	return LEN

# 입력
N = int(input())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 정렬
tmp = []
for i in range(N):
	tmp.append([X[i], -Y[i]])
tmp.sort()

# LIS를 찾아야 하는 배열은?
A = []
for i in range(N):
	A.append(-tmp[i][1])

# 출력
print(Get_LISvalue(A))
