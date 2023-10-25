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

MOD = 1000000007

# 입력
X, Y = map(int, input().split())

# 이항계수의 분자와 분모 구하기(과정1 / 과정2)
bunja, bunmo = 1, 1
for i in range(1, X + Y + 1):
	bunja = (bunja * i) % MOD
for i in range(1, X + 1):
	bunmo = (bunmo * i) % MOD
for i in range(1, Y + 1):
	bunmo = (bunmo * i) % MOD

# 답 구하기(과정3)
print(division(bunja, bunmo, MOD))
