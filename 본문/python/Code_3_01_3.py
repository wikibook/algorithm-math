# 입력
N = int(input())

# 모든 약수를 구하고, 배열 divisors에 넣음
LIMIT = int(N ** 0.5)
divisors = []
for i in range(1, LIMIT + 1):
	if N % i == 0:
		divisors.append(i)
		if i != N // i:
			divisors.append(N // i)

# 오름차순으로 정렬 → 출력
# sort는 오름차순으로 정렬하는 함수(3.6.1절에서 다룹니다)
divisors.sort()
for i in divisors:
	print(i)
