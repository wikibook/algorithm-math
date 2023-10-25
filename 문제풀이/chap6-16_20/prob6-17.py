# 입력
N = int(input())

# 세로 길이를 1부터 √N까지 전체 탐색
LIMIT = int(N ** 0.5)
answer = 10 ** 19
for i in range(1, LIMIT + 1):
	if N % i == 0:
		answer = min(answer, 2 * i + 2 * (N // i))

# 답 출력
print(answer)