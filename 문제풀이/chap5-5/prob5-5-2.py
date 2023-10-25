# 입력
N = int(input())
A = [0.0 for i in range(N)]
B = [0.0 for i in range(N)]
C = [0.0 for i in range(N)]
for i in range(N):
	A[i], B[i], C[i] = map(float, input().split())

# 교점 전체 탐색
Answer = 0.0
for i in range(0, N):
	for j in range(i + 1, N):
		# 교점을 갖지 않는 경우
		if A[i] * B[j] == A[j] * B[i]:
			continue
		
		# i번째 직선(조건식의 경계)와 j번째 직선(조건식의 경계) 사이의 교점을 구함
		px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
		py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
		
		# 좌표 (px, py)가 N개의 조건을 만족하는지 확인
		# C++ 코드에서 check 함수에 해당
		ret = True
		for k in range(N):
			if A[k] * px + B[k] * py > C[k]:
				ret = False
		
		if ret == True:
			Answer = max(Answer, px + py)

# 출력
print("{:.12f}".format(Answer))