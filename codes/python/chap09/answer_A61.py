# 입력
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 인접 리스트 생성
G = [ list() for i in range(N + 1) ] # G[i]는 버텍스 i에 인접한 버텍스의 목록
for a, b in edges:
	G[a].append(b) # 정점 a 에 인접한 정점으로 b 를 추가한다.
	G[b].append(a) # 정점 b 에 인접한 정점으로 a 를 추가한다.

# 출력
for i in range(1, N + 1):
	output = ''
	output += str(i)
	output += ': {'
	output += ', '.join(map(str, G[i])) # 예를 들어 G[i] = { 2, 7, 5 }인 경우 "2, 7, 5"라는 문자열이 output 뒤에 연결된다.
	output += '}'
	print(output)