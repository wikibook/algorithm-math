# x가 소수일 때 true, 소수가 아닐 때 false를 반환한다
def isPrime(N):
	LIMIT = int(N ** 0.5)
	for i in range(2, LIMIT + 1):
		if N % i == 0:
			return False
	return True

# 입력
Q = int(input())
X = [ None ] * Q
for i in range(Q):
	X[i] = int(input())

# 출력
for i in range(Q):
	Answer = isPrime(X[i])
	if Answer == True:
		print("Yes")
	else:
		print("No")
