import bisect
import sys

# 입력
N, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = list(map(int, input().split()))

# 배열 P를 작성
P = []
for x in range(N):
	for y in range(N):
		P.append(A[x] + B[y])

# 배열 Q를 작성
Q = []
for z in range(N):
	for w in range(N):
		Q.append(C[z] + D[w])

# 배열 Q를 오름차순으로 정렬
Q.sort()

# 바이너리 서치
for i in range(len(P)):
	pos1 = bisect.bisect_left(Q, K-P[i])
	if pos1<N*N and Q[pos1]==K-P[i]:
		print("Yes")
		sys.exit(0)

# 발견하지 못한 경우
print("No")
