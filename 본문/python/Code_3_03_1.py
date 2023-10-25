# 입력
N = int(input())
A = list(map(int, input().split()))

# 5개의 카드 번호(i, j, k, l, m)를 전체 탐색
answer = 0
for i in range(0, N):
	for j in range(i + 1, N):
		for k in range(j + 1, N):
			for l in range(k + 1, N):
				for m in range(l + 1, N):
					if A[i] + A[j] + A[k] + A[l] + A[m] == 1000:
						answer += 1

# 출력
print(answer)
