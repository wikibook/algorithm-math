# 반복제곱법(p에는 a**1, a**2, a**4, a**8, ...가 할당됨)
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m)은 a÷b mod m를 리턴하는 함수
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# 입력
X, Y = map(int, input().split())
mod = 1000000007

# a, b가 음수가 되어버리는 경우
if (2 * Y - X) < 0 or (2 * X - Y) < 0:
	print(0)

# a, b가 정수가 아닌 경우
elif (2 * Y - X) % 3 != 0 or (2 * X - Y) % 3 != 0:
	print(0)

# 답이 0이 아닐 경우
else:
	bunja = 1
	bunmo = 1
	a = (2 * Y - X) // 3
	b = (2 * X - Y) // 3
	
	# 이항 계수의 분모와 분자 구하기(과정1. / 과정2.)
	for i in range(1, a + b + 1):
		bunja *= i
		bunja %= mod
	for i in range(1, a + 1):
		bunmo *= i
		bunmo %= mod
	for i in range(1, b + 1):
		bunmo *= i
		bunmo %= mod
	
	# 답 구하기(과정3)
	print(division(bunja, bunmo, mod))