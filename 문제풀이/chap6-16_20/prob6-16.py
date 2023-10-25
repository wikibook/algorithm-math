# 입력
N, X = map(int, input().split())

# 모든 (a, b, c) 조합 확인하기
answer = 0
for a in range(1, N + 1):
	for b in range(a + 1, N + 1):
		for c in range(b + 1, N + 1):
			if a + b + c == X:
				answer += 1

# 답 출력
print(answer)