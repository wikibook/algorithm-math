# 입력
N = int(input())
A = list(map(int, input().split()))

# 답을 구한다
Answer = False
for i in range(N):
	for j in range(i+1, N):
		for k in range(j+1, N):
			if A[i] + A[j] + A[k] == 1000:
				Answer = True

# 출력
if Answer == True:
	print("Yes")
else:
	print("No")
