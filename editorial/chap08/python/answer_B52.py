from collections import deque


# 입력
N, X = map(int, input().split())
X -= 1
A = list(input())

# 시뮬레이션
Q = deque([X])
Q.append(X)
A[X] = '@'
while Q:
	pos = Q.popleft()
	if pos - 1 >= 0 and A[pos - 1] == '.':
		A[pos - 1] = '@'
		Q.append(pos - 1)
	if pos + 1 < N and A[pos + 1] == '.':
		A[pos + 1] = '@'
		Q.append(pos + 1)

# 출력
print("".join(A))
