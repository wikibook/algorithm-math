# 입력
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 모든 패턴 탐색: (1<<N)은 2의 N제곱
answer = "No"
for i in range(0, 1 << N):
	partsum = 0
	for j in range(0, N):
		# (i & (1 << j)) != 0이라면
		# i의 2진법 표기에서 아래에서 j+1번째 카드가 1이라는 의미입니다.
		# (1 << j)는 파이썬에서 "2의 j제곱을 의미합니다.
		if (i & (1 << j)) != 0:
			partsum += A[j]
	if partsum == S:
		answer = "Yes"
		break

# 출력
print(answer)
