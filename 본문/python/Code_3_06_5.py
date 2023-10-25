def solve(l, r, A):
	if r - l == 1:
		return A[l]
	m = (l + r) // 2  # 구간 [l, r)의 중앙을 기준으로 분할 정복
	s1 = solve(l, m, A)  # s1는 A[l] + ... + A[m-1]의 합계를 계산
	s2 = solve(m, r, A)  # s2는 A[m] + ... + A[r-1]는 합계를 계산
	return s1 + s2

# 입력
N = int(input())
A = list(map(int, input().split()))

# 재귀함수 호출 → 답 출력
answer = solve(0, N, A)
print(answer)
