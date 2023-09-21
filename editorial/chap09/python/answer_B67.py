N, M = map(int, input().split())

edge = []
for _ in range(M):
    A, B, C = map(int, input().split())
    A -= 1
    B -= 1
    edge.append((A, B, C))

# 길이 역순으로 정렬
edge.sort(key=lambda e: -e[2])

# union-find
uf = [-1] * N
def root(i: int) -> int:
    # path halving
    while True:
        if uf[i] < 0:
            return i
        if uf[uf[i]] < 0:
            return uf[i]
        uf[i] = uf[uf[i]]
        i = uf[i]
def unite(i: int, j: int) -> bool:
    i = root(i)
    j = root(j)
    if i == j:
        return False
    # 병합기술 (union by size)
    if uf[i] > uf[j]:
        i, j = j, i
    uf[i] += uf[j]
    uf[j] = i
    return True

# 크라스칼법
ans = 0
for A, B, C in edge:
    if unite(A, B):
        ans += C

print(ans)
