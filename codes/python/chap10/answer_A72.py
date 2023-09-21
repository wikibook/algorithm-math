import itertools

# 입력
H, W, K = map(int, input().split())
c = [ input() for i in range(H) ]

# 남은 remaining_steps번의 '열에 대응하는 조작'으로 최대 몇 개의 칸을 검은색으로 칠할 수 있는지 반환하는 함수
def paint_row(H, W, d, remaining_steps):
	# 각 열에 대해 (흰 칸을 검은색으로 칠할 수 있는 칸을 반환하는 함수
	column = [ ([ d[i][j] for i in range(H) ].count('.'), j) for j in range(W) ]
	column.sort(reverse = True)

	# 열에 대한 조작을 수행한다
	for j in range(remaining_steps):
		idx = column[j][1]
		for i in range(H):
			d[i][idx] = '#'
	
	# 검은색 칸의 개수를 계산하여 이를 반환한다
	return sum(map(lambda l: l.count('#'), d))

# 행을 채우는 방법을 완전 탐색
# (여기서는 '비트 완전 탐색'이 아닌 itertools.product를 사용하여 2^H 거리의 채색 방법을 모두 열거한다)
answer = 0
for v in itertools.product([ 0, 1 ], repeat = H):
	# 행에 대해 조작을 수행한다(paint_row 함수에서 일부 d[i][j]를 재작성하기 위해 d는 문자열 배열이 아닌 2 차원 목록으로 설정합니다)
	d = [ list(c[i]) for i in range(H) ]
	remaining_steps = K
	for i in range(H):
		if v[i] == 1:
			d[i] = [ '#' ] * W
			remaining_steps -= 1
	if remaining_steps >= 0:
		subanswer = paint_row(H, W, d, remaining_steps)
		answer = max(answer, subanswer)

# 출력
print(answer)