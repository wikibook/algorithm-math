def MergeSort(A):
	# 길이가 1이라면 이미 정렬되어 있으므로, 아무것도 하지 않음
	if len(A) == 1:
		return A
	
	# 2개로 분할하고, 분할한 배열을 정렬함
	m = len(A) // 2
	A_Dash = MergeSort(A[0:m])
	B_Dash = MergeSort(A[m:len(A)])
	
	# 이 시점에서 다음 두 배열이 정렬 완료됨
	# 배열 A' [A_Dash[0], A_Dash[1], ..., A_Dash[m-1]]
	# 배열 B' [B_Dash[0], B_Dash[1], ..., B_Dash[len(A)-m-1]]
	# 다음 코드들은 Merge 조작에 해당하는 부분
	c1 = 0
	c2 = 0
	C = []
	while (c1 < len(A_Dash) or c2 < len(B_Dash)):
		if c1 == len(A_Dash):
			# 배열 A'가 빈 경우
			C.append(B_Dash[c2])
			c2 += 1
		elif c2 == len(B_Dash):
			# 배열 B'가 빈 경우
			C.append(A_Dash[c1])
			c1 += 1
		else:
			# 둘 다 아닌 경우
			if A_Dash[c1] <= B_Dash[c2]:
				C.append(A_Dash[c1])
				c1 += 1
			else:
				C.append(B_Dash[c2])
				c2 += 1
	
	# 배열 A', 배열 B'를 Merge한 배열 C를 리턴
	return C

# 메인 부분
N = int(input())
A = list(map(int, input().split()))

# 병합정렬 → 답 출력
Answer = MergeSort(A)
print(*Answer)