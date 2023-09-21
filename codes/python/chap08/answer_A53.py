import heapq

# 입력
Q = int(input()) #  쿼리 개수
queries = [ input().split() for i in range(Q) ] # 쿼리 정보(각 요소는 ["1", 값을 나타내는 문자열] or ["2"] or ["3"]이다.)

# 쿼리 처리
T = []
for q in queries:
	if q[0] == "1":
		heapq.heappush(T, int(q[1]))
	if q[0] == "2":
		print(T[0]) # T[0]은 '우선순위 대기열 중 가장 작은 요소'이다.
	if q[0] == "3":
		heapq.heappop(T)

# 참고 1: Python의 heapq 모듈은 deque 모듈과 달리 함수를 사용하여 list를 조작하는 형식이다.
# 참고 2: 우선순위가 있는 큐의 최소 요소는 T[0]으로 가져올 수 있지만, 예를 들어 작은 것부터 두 번째 요소는 T[1]로 가져올 수 있는 것은 아니라는 점에 유의한다.