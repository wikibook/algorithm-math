# 이 코드는 깊이 우선 탐색(DFS)를 스택으로 구현한 예입니다.
# 스택은 "가장 위에 요소를 추가한다", "가장 위의 요소를 확인한다", "가장 위의 요소를 꺼낸다"라는 3가지 조작을 할 수 있는 자료구조입니다.
# 깊이 우선 탐색 부분은 코드 4.5.3의 큐를 스택으로 변경한 것을 기반으로 작성했습니다.

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

# 깊이 우선 탐색 초기화
visited = [ False ] * (N + 1)
S = list() # 스택S 정의
visited[1] = True
S.append(1) # S에 1을 추가

# 깊이 우선 탐색
while len(S) >= 1:
	pos = S.pop() # S의 앞부분을 확인하고 꺼냄
	for nex in G[pos]:
		if visited[nex] == False:
			visited[nex] = True
			S.append(nex) # S에 nex를 추가

# 연결 판정(answer = true일 때 연결)
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")