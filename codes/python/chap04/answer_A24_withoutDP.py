###########################
# 배열 dp를 사용하지 않는 구현 
###########################

import bisect

# 입력(A는 0번부터 시작한다는 점에 주의!)
N = int(input())
A = list(map(int, input().split()))

# 동적 계획 알고리즘의 준비
LEN = 0
L = []

# 동적 계획 알고리즘(배열 dp를 이용한 구현)
for i in range(N):
	pos = bisect.bisect_left(L, A[i])
	if pos >= LEN:
		L.append(A[i])
		LEN += 1
	else:
		L[pos] = A[i]

# 답을 출력
print(LEN)
