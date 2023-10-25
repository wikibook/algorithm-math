# 입력
N = int(input())
A = list(map(int, input().split()))

# 배열 초기화
dp1 = [ None ] * (N + 1)
dp2 = [ None ] * (N + 1)
dp1[0] = 0
dp2[0] = 0

# 동적계획법
for i in range(1, N + 1):
	dp1[i] = dp2[i - 1] + A[i - 1]
	dp2[i] = max(dp1[i - 1], dp2[i - 1])

# 출력
Answer = max(dp1[N], dp2[N])
print(Answer)