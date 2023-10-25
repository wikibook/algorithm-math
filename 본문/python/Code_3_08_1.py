# 입력
N, X = map(int, input().split())
A = list(map(int, input().split()))

# 배열 정렬
A.sort()

# 이진 탐색
answer = "No"
left, right = 0, N - 1
while left <= right:
	mid = (left + right) // 2
	if A[mid] == X:
		answer = "Yes"
		break
	if A[mid] > X:
		# 탐색 범위를 앞부분으로 변경
		right = mid - 1
	if A[mid] < X:
		# 탐색 범위를 뒷부분으로 변경
		left = mid + 1

# 답 출력
print(answer)
