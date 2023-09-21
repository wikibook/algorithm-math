# 입력
Q = int(input()) # 쿼리 개수
queries = [ input().split() for i in range(Q) ] # 쿼리 정보(각 요소는 ["1", 이름을 나타내는 문자열, 점수를 나타내는 문자열] or ["2", 이름을 나타내는 문자열]로 구성됨)

# 쿼리 처리
Map = {}
for q in queries:
	if q[0] == "1":
		Map[q[1]] = q[2]
	if q[0] == "2":
		print(Map[q[1]])