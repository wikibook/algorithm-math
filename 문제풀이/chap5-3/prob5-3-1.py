# 입력
H, W = map(int, input().split())

# 조건 분기
if H == 1 or W == 1:
	print(1)
else:
	print((H * W + 1) // 2)