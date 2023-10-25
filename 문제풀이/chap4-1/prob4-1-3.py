# 입력
X1,Y1,R1 = map(float, input().split())
X2,Y2,R2 = map(float, input().split())

# 원 중심과의 거리 구하기
d = (((X1 - X2) ** 2 + (Y1 - Y2) ** 2) ** 0.5)

# 답 출력
if d < abs(R1 - R2):
	print("1")
elif d == abs(R1 - R2):
	print("2")
elif d < R1 + R2:
	print("3")
elif d == R1 + R2:
	print("4")
else:
	print("5")