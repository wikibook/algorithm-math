# 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
# GCD는 Greatest Common Divisor(최대 공약수)의 약자
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B라면, 큰 수를 b로 변경합니다.
		else:
			A = A % B  # A >= B라면 큰 수를 a로 변경합니다.
	if A >= 1:
		return A
	return B

A, B = map(int, input().split())
print(GCD(A, B))
