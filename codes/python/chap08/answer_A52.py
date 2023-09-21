from collections import deque

# 입력
Q = int(input()) # 쿼리 개수
queries = [ input().split() for i in range(Q) ] # 쿼리 정보(각 요소는 ["1", 이름을 나타내는 문자열] or ["2"] or ["3"]이다.)

# 쿼리 처리
T = deque()
for q in queries:
	if q[0] == "1":
		T.append(q[1])
	if q[0] == "2":
		print(T[0])
	if q[0] == "3":
		T.popleft()