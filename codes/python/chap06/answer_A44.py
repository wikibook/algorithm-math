# 입력・배열 준비
N, Q = map(int, input().split())
State = 1
E = [ None ] * (N+2)
for i in range(1, N+1):
	E[i] = i

# 쿼리 처리
for i in range(Q):
	Query = input().split()

	# [1] 변경 조작
	if int(Query[0]) == 1:
		x = int(Query[1])
		y = int(Query[2])
		if State == 1:
			E[x] = y
		if State == 2:
			E[N+1-x] = y

	# [2] 반전 조작
	if int(Query[0]) == 2:
		if State == 1:
			State = 2
		else:
			State = 1

	# [3] 취득 조작
	if int(Query[0]) == 3:
		x = int(Query[1])
		if State == 1:
			print(E[x])
		if State == 2:
			print(E[N+1-x])
