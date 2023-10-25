# 입력
N = int(input())

# 답 계산
Answer = 0.0
for i in range(1, N+1):
	Answer += 1.0 * N / i

# 출력
print("{:.12f}".format(Answer))