# 입력
N = int(input())
L = [ None ] * N
R = [ None ] * N
for i in range(N):
	L[i], R[i] = map(int, input().split())

# 영화 선택 시뮬레이션
# 볼 수 있는 영화 중 종료 시간 최솟값 min_endtime은 일단 1000000(INF로 설정)처럼 나올 수 없는 값으로 설정합니다.
INF = 1000000
current_time = 0  # current_time는 현재 시각(직전에 보았던 영화의 종료 시각)
answer = 0
while True:
	min_endtime = INF
	for i in range(N):
		if L[i] >= current_time:
			min_endtime = min(min_endtime, R[i])
	if min_endtime == INF:
		break
	current_time = min_endtime
	answer += 1

# 답 출력
print(answer)
