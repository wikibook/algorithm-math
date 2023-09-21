import sys
sys.setrecursionlimit(1 << 20)  # 재귀 상한이 기본적으로 1000으로 설정되어 있으므로 변경한다

# 입력
N, M = map(int, input().split())
g = [[] for _ in range(N)]
for i in range(M):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    g[A].append(B)
    g[B].append(A)

# 깊이 우선 탐색
visited = [False] * (N + 1)
path = []

def dfs(i: int):
    path.append(i)
    # 결승점에 도착한 경우
    if i == N - 1:
        # 답을 출력하고 종료
        for x in path:
            print(x + 1) # 1-indexed로 변경
        exit(0)

    # 그 외의 경우
    visited[i] = True
    for j in g[i]:
        if not visited[j]:
            dfs(j)
    path.pop()

dfs(0)
