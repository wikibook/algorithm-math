# 입력
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
L = [ None ] * Q
R = [ None ] * Q
for i in range(Q):
	L[i], R[i] = map(int, input().split())

# 일치하는 개수와 불일치하는 개수의 누적합을 구한다.
# 배열 A 가 0 번부터 시작한다는 점에 주의!
Atari = [ 0 ] * (N + 1)
Hazre = [ 0 ] * (N + 1)
for i in range(1, N+1):
	# Atari에 대한 계산
	Atari[i] = Atari[i - 1]
	if A[i - 1] == 1:
		Atari[i] += 1
	# Hazre에 대해 계산
	Hazre[i] = Hazre[i - 1]
	if A[i - 1] == 0:
		Hazre[i] += 1

# 질문에 답한다
for i in range(Q):
	NumAtari = Atari[R[i]] - Atari[L[i] - 1]
	NumHazre = Hazre[R[i]] - Hazre[L[i] - 1]
	if NumAtari > NumHazre:
		print("win")
	elif NumAtari == NumHazre:
		print("draw")
	else:
		print("lose")
