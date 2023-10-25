# 정수 m의 각 자릿수 곱을 리턴하는 함수
def product(m):
	if m == 0:
		return 0
	ans = 1
	while m >= 1:
		ans *= (m % 10)
		m //= 10
	return ans

# 각 자릿수의 곱 후보 집합을 리턴하는 함수
def func(digit, m):
	if digit == 11:
		return {product(m)}
	
	# 다음 자리 탐색
	# min_value은 cur의 마지막 자리(숫자가 오름차순으로 정렬되어 있으므로, 다음 자리는 이전 자리보다 크거나 같을 것입니다).
	min_value = m % 10
	ret = set()
	for i in range(min_value, 10):
		r = func(digit + 1, m * 10 + i)
		for j in r:
			ret.add(j)
	return ret

# 입력
N, B = map(int, input().split())

# 각 자릿수의 곱 후보를 모두 나열
fm_cand = func(0, 0)

# m - f(m) = B이 되는지 확인
Answer = 0
for fm in fm_cand:
	m = fm + B # 각 자릿수의 곱으로 도출된 m의 값
	prod_m = product(m) # 원래 f(m)의 값
	if m - prod_m == B and m <= N:
		Answer += 1

# 출력
print(Answer)