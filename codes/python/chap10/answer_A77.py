# 입력
N, L = map(int, input().split())
K = int(input())
A = list(map(int, input().split()))

# 점수의 최대값이 x 이상인지 판단하는 함수
def check(x):
	cnt = 0         # 현재 시점에서 몇 번을 자른 것인지 표시
	last_kireme = 0 # 마지막으로 자른 위치를 나타낸다
	for i in range(N):
		if A[i] - last_kireme >= x and L - A[i] >= x:
			cnt += 1
			last_kireme = A[i]
	return cnt >= K

# 바이너리 서치(left: 현재 상한 / right: 현재 하한)
left, right = 1, 10 ** 9
while left < right:
	mid = (left + right + 1) // 2
	answer = check(mid)
	if answer == False:
		right = mid - 1 # 답이 전반 부분으로 좁혀진다
	else:
		left = mid      # 답이 후반 부분으로 좁혀진다

# 출력
print(left)