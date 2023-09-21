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

# 입력
a, b = map(int, input().split())

# 출력
print(Power(a, b, 1000000007))
