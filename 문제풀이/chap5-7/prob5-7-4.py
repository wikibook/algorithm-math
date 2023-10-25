# 입력
N = int(input())
X = [0 for i in range(N)]
Y = [0 for i in range(N)]
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 배열 X, Y 정렬하기
X.sort()
Y.sort()

# Part1의 답(x 좌표 차의 절댓값 총합)
Part1 = 0
for i in range(1, N + 1):
	Part1 += X[i - 1] * (-N + 2 * i - 1);

# Part2의 답(y 좌표 차의 절댓값 총합)
Part2 = 0
for i in range(1, N + 1):
	Part2 += Y[i - 1] * (-N + 2 * i - 1);

# 출력
print(Part1 + Part2)