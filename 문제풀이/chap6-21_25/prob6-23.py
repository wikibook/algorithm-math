# 입력
L, R = map(int, input().split())

# 배열 초기화/L=1  때의 조건 분기
isprime = [ True ] * (R - L + 1)
if L == 1:
	isprime[0] = False

# 에라토스테네스의 체
LIMIT = int(R ** 0.5)
for i in range(2, LIMIT + 1):
	min_value = ((L + i - 1) // i) * i
	for j in range(min_value, R + 1, i):
		if j == i:
			continue
		isprime[j - L] = False

# 갯수 세서 출력하기
answer = 0
for i in range(R - L + 1):
	if isprime[i] == True:
		answer += 1
print(answer)