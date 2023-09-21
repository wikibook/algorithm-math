# 입력
N, X = map(int, input().split())
A = list(map(int, input().split()))
Answer = False

# 완전 탐색(변수 Answer는 '기존에 x를 발견했는가'를 나타냄)
for i in range(N):
	if A[i] == X:
		Answer = True

# 출력
if Answer == True:
	print("Yes")
else:
	print("No")
