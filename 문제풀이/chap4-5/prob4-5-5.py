# 입력
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 인접리스트 작성
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 답 구하기
answer = 0
for i in range(1, N + 1):
	cnt = 0
	for j in G[i]:
		if j < i:
			cnt += 1
	# 자기자신보다 번호가 작은 인접한 정점이 1개 있다면, answer에 1을 추가
	if cnt == 1:
		answer += 1

# 답 출력
print(answer)
