# 입력
N = int(input())
A = [ None ] * N
for i in range(N):
	A[i] = list(map(int, input().split()))

# 배열 T 초기화
# 배열 A가 0으로 시작하므로 배열 T도 0으로 시작한다
T = [ None ] * N
for i in range(N):
	T[i] = i

# 쿼리 처리
Q = int(input())
for i in range(Q):
	Query = list(map(int, input().split()))
	if Query[0] == 1:
		T[Query[1]-1],T[Query[2]-1] = T[Query[2]-1],T[Query[1]-1]
	if Query[0] == 2:
		print(A[T[Query[1]-1]][Query[2]-1])
