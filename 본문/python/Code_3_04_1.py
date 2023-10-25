# 입력
N = int(input())
B = list(map(int, input().split()))
R = list(map(int, input().split()))

# 답 계산
blue = 0.0
red = 0.0
for i in range(N):
	blue += B[i] // N
	red += R[i] // N

# 출력
print("{:.12f}".format(blue + red))
