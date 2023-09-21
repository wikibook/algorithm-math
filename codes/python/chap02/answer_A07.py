# 입력
D = int(input())
N = int(input())
L = [ None ] * N
R = [ None ] * N
for i in range(N):
	L[i], R[i] = map(int, input().split())

# 전일 비에 더한다
B = [ 0 ] * (D+2)
for i in range(N):
	B[L[i]] += 1
	B[R[i]+1] -= 1

# 누적 합을 구한다
Answer = [ None ] * (D+2)
Answer[0] = 0
for d in range(1, D+1):
	Answer[d] = Answer[d - 1] + B[d]

# 출력
for d in range(1, D+1):
	print(Answer[d])
