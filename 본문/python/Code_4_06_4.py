# 반복제곱법(p에는 a**1, a**2, a**4, a**8, ...가 할당됨)
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

MOD = 1000000007

a, b = map(int, input().split())
print(modpow(a, b, MOD))

# 추가
# 참고적으로 Python에는 "a**b"를 m으로 나눈 나머지"를 반복제곱법으로 구하는 함수가
# 표준 라이브러리에 pow(a, b, m)로 구현되어 있습니다.
# 이와 관련된 내용은 Code_4_06_4_extra.py를 참고해주세요.
