# 입력
N = int(input())

# 10의 N 제곱 찾기
Power10 = [ None ] * 17
for i in range(17):
	Power10[i] = 10 ** i

# R[i][j]의 값 계산
R = [ [ None ] * 10 for i in range(17) ]
for i in range(16):
	# 아래에서 i 번째 자리의 숫자를 찾습니다.
	Digit = (N // Power10[i]) % 10;

	# R[i][j] 값 구하기
	for j in range(10):
		if j < Digit:
			R[i][j] = (N // Power10[i + 1] + 1) * Power10[i]
		if j == Digit:
			R[i][j] = (N // Power10[i + 1]) * Power10[i] + (N % Power10[i]) + 1
		if j > Digit:
			R[i][j] = (N // Power10[i + 1]) * Power10[i]

# 답을 구한다
Answer = 0
for i in range(16):
	for j in range(10):
		Answer += j * R[i][j]

# 출력
print(Answer)
