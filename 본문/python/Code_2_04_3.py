# 입력
N, S = map(int, input().split())

# 답 구하기
answer = 0
for i in range(1, N + 1):
	for j in range(1, N + 1):
		if i + j <= S:
			answer += 1

# 출력
print(answer)
