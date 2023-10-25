# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
a = 0
b = 0
c = 0
d = 0
for i in range(N):
	if A[i] == 100:
		a += 1
	if A[i] == 200:
		b += 1
	if A[i] == 300:
		c += 1
	if A[i] == 400:
		d += 1

# 출력
print(a * d + b * c)