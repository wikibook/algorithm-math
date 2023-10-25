# 2 이상의 정수 N을 매개변수로 받고, N이 소수라면 True를,
# 아니라면 False를 리턴하는 함수
def isprime(N):
	for i in range(2, N):
		if N % i == 0:
			return False # N이 i으로 나누어지는 경우, 이 시점에서 소수가 아니라는 것을 알 수 있음
	return True

N = int(input())
if isprime(N):
	print("prime")
else:
	print("not prime")
