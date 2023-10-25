# 최대공약수를 리턴하는 함수
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B라면, 큰 수를 b로 변경합니다.
		else:
			A = A % B  # A >= B라면 큰 수를 a로 변경합니다.
	if A >= 1:
		return A
	return B

# 최소공배수를 리턴하는 함수
def LCM(A, B):
	return int(A / GCD(A, B)) * B

# 입력
N, K = map(int, input().split())
V = list(map(int, input().split()))

# 비트 전체 탐색
Answer = 0
for i in range(1, 1 << K):
	cnt = 0
	lcm = 1
	for j in range(K):
		if (i & (1 << j)) != 0:
			cnt += 1
			lcm = LCM(lcm, V[j])
			
	# num은 N 이하 중에서 선택된 숫자 모두의 배수인 것의 개수
	num = N // lcm
	if cnt % 2 == 1:
		Answer += num
	else:
		Answer -= num

# 출력
print(Answer)