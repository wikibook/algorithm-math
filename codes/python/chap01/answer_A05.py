# 입력
N, K = map(int, input().split())
Answer = 0

# 완전 탐색
for x in range(1, N+1):
	for y in range(1, N+1):
		z = K - x - y
		if z >= 1 and z <= N:
			Answer += 1

# 출력
print(Answer)
