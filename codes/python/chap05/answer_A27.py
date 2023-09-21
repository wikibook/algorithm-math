def GCD(A, B):
	while A >= 1 and B >= 1:
		if A >= B:
			A = A % B # A의 값을 변경하는 경우
		else:
			B = B % A # B의 값을 변경하는 경우
	if A >= 1:
		return A
	return B

# 입력
A, B = map(int, input().split())
print(GCD(A, B))
