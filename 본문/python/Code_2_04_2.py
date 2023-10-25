# 입력
N, X, Y = map(int, input().split())

# 답 구하기
cnt = 0
for i in range(1, N + 1):
	# mod 계산은 2.2절 참고
	if i % X == 0 or i % Y == 0:
		cnt += 1

# 출력
print(cnt)
