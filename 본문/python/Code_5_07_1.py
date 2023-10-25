# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
answer = 0
for i in range(N):
	# i = 0부터 시작하므로, "-N + 2 * i - 1"가 아니라, "-N + 2 * i + 1"를 곱했음
	answer += A[i] * (-N + 2 * i + 1)

# 답 출력
print(answer)
