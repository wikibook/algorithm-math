import bisect


INF = 1 << 61
siz = 1 << 17
dat = [INF] * (siz * 2)

# 대입 seg[i] = v
def update(i: int, v: int) -> None:
	i += siz
	dat[i] = v
	while i > 1:
		i >>= 1
		dat[i] = min(dat[i * 2], dat[i * 2 + 1])

# min(seg[l], seg[l + 1], ..., seg[r - 1])을 구한다
def query(l: int, r: int) -> int:
	l += siz
	r += siz
	answer = INF
	while l < r:
		if l & 1:
			if answer > dat[l]:
				answer = dat[l]
			l += 1
		if r & 1:
			r -= 1
			if answer > dat[r]:
				answer = dat[r]
		l >>= 1
		r >>= 1
	return answer

# 입력
N, L, R = map(int, input().split())
X = list(map(int, input().split()))
dp = [0] * N

# 동적 계획 알고리즘
update(0, 0)
for i in range(1, N):
	x = X[i]
	posL = bisect.bisect_left(X, x - R)
	posR = bisect.bisect_right(X, x - L)
	dp[i] = query(posL, posR) + 1
	update(i, dp[i])

print(dp[-1])
