# 입력
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 인접리스트 작성
G = [ list() for i in range(N + 1) ] # G[i]는 정점i와 인접한 정점 리스트
for i in range(M):
	G[A[i]].append(B[i]) # 정점 A[i]와 인접한 정점으로 B[i]를 추가
	G[B[i]].append(A[i]) # 정점 B[i]와 인접한 정점으로 A[i]를 추가

# 출력(len(G[i])은 정점i와 인접한 정점 리스트의 크기 = 차수)
for i in range(1, N + 1):
	output = str(i) + ": {"
	for j in range(len(G[i])):
		if j >= 1:
			output += ","
		output += str(G[i][j]) # G[i][j]는 정점i와 인접한 정점 중 j+1번째인 것
	output += "}"
	print(output)
