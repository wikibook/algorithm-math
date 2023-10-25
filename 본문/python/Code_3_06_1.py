# 입력(예를 들어서 N = 5, A = [3, 1, 4, 1, 5]를 입력하면)
N = int(input())
A = list(map(int, input().split()))

# 배열A 전체를 정렬
A.sort()

# 출력(1, 1, 3, 4, 5 순서로 출력됨)
for i in range(N):
	print(A[i])
