# 2 이상의 정수 N을 매개변수로 받고, N이 소수라면 True를,
# 아니라면 False를 리턴하는 함수
def isprime(N):
	LIMIT = int(N ** 0.5)
	for i in range(2, LIMIT + 1):
		if N % i == 0:
			return False
	return True

N = int(input())
if isprime(N):
	print("prime")
else:
	print("not prime")
