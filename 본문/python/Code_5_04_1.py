# 입력
N, K = map(int, input().split())

# 사건B의 개수를 yeosagun(여사건) 변수로 셉니다.
yeosagun = 0
for a in range(1, N + 1):
	l = max(1, a - (K - 1)) # b, c의 탐색 범위 하한 l
	r = min(N, a + (K - 1)) # b, c의 탐색 범위 상한 r
	for b in range(l, r + 1):
		for c in range(l, r + 1):
			if abs(b - c) <= K - 1:
				yeosagun += 1

# 답 출력
print(N ** 3 - yeosagun)
