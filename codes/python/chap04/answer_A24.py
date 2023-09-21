import bisect

# 입력(A는 0번부터 시작한다는 점에 주의!)
N = int(input())
A = list(map(int, input().split()))

# 동적 계획 알고리즘의 준비
LEN = 0 # LEN은 L의 길이 (예: L[3]까지 기록된 경우 LEN=4)
L = []  # 0부터 시작하는 것에 주의
dp = [ None ] * N # 0부터 시작하는 것에 주의

# 동적 계획 알고리즘(배열 dp를 이용한 구현)
for i in range(N):
	pos = bisect.bisect_left(L, A[i])
	dp[i] = pos

	# 배열 L을 업데이트
	if dp[i] >= LEN:
		L.append(A[i])
		LEN += 1
	else:
		L[dp[i]] = A[i]

# 답을 출력
print(LEN)
