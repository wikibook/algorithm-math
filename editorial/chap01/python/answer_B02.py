# 입력
A, B = map(int, input().split())

# 답을 구한다
Answer = False
for i in range(A, B + 1):
	if 100 % i == 0:
		Answer = True

# 출력
if Answer == True:
	print("Yes")
else:
	print("No")
