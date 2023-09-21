# 입력
N = int(input())
A = list(map(int, input().split()))
D = int(input())
L = [ None ] * D
R = [ None ] * D
for d in range(D):
	L[d], R[d] = map(int, input().split())

# P[i]를 구한다
# P[0] 등으로 되어 있는 것은 배열이 0으로 시작되기 때문에
P = [ None ] * N
P[0] = A[0]
for i in range(1, N):
	P[i] = max(P[i-1], A[i])

# Q[i]를 구한다
# Q[N-1] 등으로 되어 있는 것은 배열이 0으로 시작되기 때문에
Q = [ None ] * N
Q[N-1] = A[N-1]
for i in reversed(range(0,N-1)):
	Q[i] = max(Q[i+1], A[i])

# 각 날짜에 대해 답을 구한다
# (L[d]-1)-1 등으로 되어 있는 것은 배열이 0으로 시작되기 때문에
for d in range(D):
	print(max(P[(L[d]-1)-1], Q[(R[d]+1)-1]))
