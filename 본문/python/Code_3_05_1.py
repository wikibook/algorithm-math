import random

N = 10000 # N은 시행 횟수(적절하게 변경해서 사용해 주세요)
M = 0
for i in range(N):
	px = random.random() # 0 이상, 1 미만의 랜덤한 수 생성
	py = random.random() # 0 이상, 1 미만의 랜덤한 수 생성
	# 원점에서의 거리 sqrt(px * px + py * py)가
	# 1이어야 하므로, 양쪽에 제곱해서 px * px + py * py <= 1을 확인
	if px * px + py * py <= 1.0:
		M += 1

print("{:.12f}".format(4 * M / N))
