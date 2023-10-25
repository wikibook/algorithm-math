def check_numpoints(N, X, Y, lx, rx, ly, ry):
	cnt = 0
	for i in range(N):
		# 점(X[i], Y[i])가 직사각형에 포함되어 있는지 판정
		if lx <= X[i] and X[i] <= rx and ly <= Y[i] and Y[i] <= ry:
			cnt += 1
	return cnt

# 입력
N, K = map(int, input().split())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 왼쪽 끝 x, 오른쪽 끝 x, 아래쪽 끝 y, 위쪽 끝 y를 전체 탐색(각각 번호가 i, j, k, l)
answer = 10 ** 19  # 일단 나올 수 없는 값을 설정
for i in range(N):
	for j in range(N):
		for k in range(N):
			for l in range(N):
				# cl <= x <= cr, dl <= y <= dr인 직사각형
				# 직사각형이 만들어지려면, cl < cr, dl < dr이어야 하므로
				cl, cr, dl, dr = X[i], X[j], Y[k], Y[l]
				if cl < cr and dl < dr:
					if check_numpoints(N, X, Y, cl, cr, dl, dr) >= K:
						area = (cr - cl) * (dr - dl)
						answer = min(answer, area)

# 답 출력
print(answer)