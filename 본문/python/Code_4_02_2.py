# 입력
N, Q = map(int, input().split())
L = [ None ] * Q
R = [ None ] * Q
X = [ None ] * Q
for i in range(Q):
	L[i], R[i], X[i] = map(int, input().split())

# 계차 계산하기
B = [ 0 ] * (N + 2)
for i in range(Q):
	B[L[i]] += X[i]
	B[R[i] + 1] -= X[i]

# 답을 계산하고 출력
answer = ""
for i in range(2, N + 1):
	if B[i] > 0:
		answer += "<"
	if B[i] == 0:
		answer += "="
	if B[i] < 0:
		answer += ">"
print(answer)
