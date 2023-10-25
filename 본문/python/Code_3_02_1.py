# 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
# GCD는 Greatest Common Divisor(최대 공약수)의 약자
def GCD(A, B):
	answer = 0
	for i in range(1, min(A, B) + 1):
		if A % i == 0 and B % i == 0:
			answer = i
	return answer

A, B = map(int, input().split())
print(GCD(A, B))
