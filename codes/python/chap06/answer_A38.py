# 입력
D, N = map(int, input().split())
L = [ None ] * N
R = [ None ] * N
H = [ None ] * N
for i in range(N):
	L[i], R[i], H[i] = map(int, input().split())

# 배열 초기화(1일은 24시간)
LIM = [ 24 ] * (D + 1)

# 상한 값을 구한다
for i in range(N):
	for j in range(L[i], R[i]+1):
		LIM[j] = min(LIM[j], H[i])

# 답을 출력
Answer = 0
for i in range(1, D+1):
	Answer += LIM[i]
print(Answer)
