import heapq


G = [list() for _ in range(2005)] # G[i]는 i 일째부터 시작하는 직업의 급여 목록이다

# 입력
N, D = map(int, input().split())
for _ in range(N):
	X, Y = map(int, input().split())
	G[X].append(Y)

# 답을 구한다
Q = []
Answer = 0
for i in range(1, D + 1):
	# i 일차부터 시작하는 작업을 대기열에 추가한다
	# heap 은 최소값을 가져 오기 때문에 -1 배로 한다
	for y in G[i]: heapq.heappush(Q, -y)

	# 할 일을 선택하고 해당 작업을 대기열에서 삭제한다
	if Q:
		Answer -= heapq.heappop(Q)

# 출력
print(Answer)
