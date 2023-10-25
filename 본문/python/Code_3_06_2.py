# 입력
N = int(input())
A = list(map(int, input().split()))

# 선택 정렬
for i in range(N - 1):
	min_position = i
	min_value = A[i]
	for j in range(i + 1, N):
		if A[j] < min_value:
			min_position = j  # min_position는 최솟값의 인덱스(0~N-1)
			min_value = A[j]  # min_value는 현재 시점에서의 최솟값
	# A[i]과 A[min_position]을 스왑
	A[i], A[min_position] = A[min_position], A[i]

# 출력
for i in range(N):
	print(A[i])
