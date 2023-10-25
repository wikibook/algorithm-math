# 입력 → 배열 prime 초기화
N = int(input())
prime = [ True ] * (N + 1)

# 에라토스테네스의 체
LIMIT = int(N ** 0.5)
for i in range(2, LIMIT + 1):
	if prime[i] == True:
		# x = 2i, 3i, 4i, ...로 N 이하의 범위에서 반복
		for j in range(2 * i, N + 1, i):
			prime[j] = False

# N 이하의 소수를 오름차순으로 출력
for i in range(2, N + 1):
	if prime[i] == True:
		print(i)
