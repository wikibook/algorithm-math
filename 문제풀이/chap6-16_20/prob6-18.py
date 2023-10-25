# 유클리드 호제법을 사용해서 최대공약수를 구합니다(다른 방법으로는 표준 라이브러리의 math.gcd(A, B)를 사용하는 방법이 있습니다).
def GCD(A, B):
	if B == 0:
		return A
	return GCD(B, A % B)

# 입력
A, B = map(int, input().split())

# 최소 공배수 구하기(참고: Python에서는 오버플로를 신경쓰지 않아도 됩니다)
L = A * B // GCD(A, B)
if L > 10 ** 18:
	print("Large")
else:
	print(L)