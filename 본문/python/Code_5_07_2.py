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

# ncr은 n!를 r! × (n-r)!으로 나눈 값
def ncr(n, r):
	global fact, MOD
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD)

MOD = 1000000007
LIMIT = 200000

# 배열 fact의 초깃값(fact[i]은 i 팩토리얼을 1000000007로 나눈 나머지)
fact = [ None ] * (LIMIT + 1)
fact[0] = 1
for i in range(1, LIMIT + 1):
	fact[i] = fact[i - 1] * i % MOD

# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
answer = 0
for i in range(N):
	answer += A[i] * ncr(N - 1, i)
	answer %= MOD

# 답 출력
print(answer)
