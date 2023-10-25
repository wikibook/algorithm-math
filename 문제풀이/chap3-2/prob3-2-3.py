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
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
R = LCM(A[0], A[1])
for i in range(2, N):
	R = LCM(R, A[i])

# 출력
print(R)