# 입력
N = int(input())
 
# N = 2^k-1 형태로 나타낼 수 있는지 확인하기
flag = False
for i in range(1, 60):
	if N == (2 ** i) - 1:
		flag = True
 
if flag == True:
	print("Second")
else:
	print("First")