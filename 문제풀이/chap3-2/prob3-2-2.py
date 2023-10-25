# 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B라면, 큰 수를 b로 변경합니다.
		else:
			A = A % B  # A >= B라면 큰 수를 a로 변경합니다.
	if A >= 1:
		return A
	return B

# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
R = GCD(A[0], A[1])
for i in range(2, N):
	R = GCD(R, A[i])

# 출력
print(R)