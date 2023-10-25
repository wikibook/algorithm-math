import sys

# 입력
a, b, c = map(int, input().split())

# c = 1 때의 조건 분기
if c == 1:
	print("No")
	sys.exit()

# 좌변 계산(c의 b 제곱)
v = 1
for i in range(b):
	v *= c
	if a < v:
		print("Yes")
		sys.exit()

# 출력(No의 경우)
print("No")