# a의 b제곱을 m으로 나눈 나머지를 반환하는 함수
def Power(a, b, m):
	p = a
	Answer = 1
	for i in range(30):
		wari = 2 ** i
		if (b // wari) % 2 == 1:
			Answer = (Answer * p) % m # a의 2^i 제곱을 곱할 때
		p = (p * p) % m
	return Answer

# a÷b를 m으로 나눈 나머지를 반환하는 함수
def Division(a, b, m):
	return (a * Power(b, m - 2, m)) % m

# 입력 등
n, r = map(int, input().split())
M = 1000000007

# 1단계: 분자 찾기
a = 1
for i in range(1, n + 1):
	a = (a * i) % M

# 2단계: 분모 찾기
b = 1
for i in range(1, r+1):
	b = (b * i) % M
for i in range(1, n-r+1):
	b = (b * i) % M

# 3단계: 답을 구한다
print(Division(a, b, M))
