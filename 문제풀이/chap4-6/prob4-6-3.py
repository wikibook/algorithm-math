# 반복제곱법(p에는 a**1, a**2, a**4, a**8, ...가 할당됨)
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(60):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m)은 a÷b mod m를 리턴하는 함수
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# 입력
MOD = 1000000007
N = int(input())

# 답 계산
V = modpow(4, N + 1, MOD) - 1
Answer = division(V, 3, MOD)

# 출력
print(Answer)