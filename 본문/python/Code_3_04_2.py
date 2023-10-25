# 입력
N = int(input())
P = [ None ] * N
Q = [ None ] * N
for i in range(N):
	P[i], Q[i] = map(int, input().split())

# 답 계산
answer = 0
for i in range(N):
	answer += Q[i] / P[i]

# 출력
print("{:.12f}".format(answer))
