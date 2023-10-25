import math

# 입력
ax, ay = map(int, input().split())
bx, by = map(int, input().split())
cx, cy = map(int, input().split())

# 벡터 BA, BC, CA, CB의 성분 표시를 구함
BAx, BAy = ax - bx, ay - by
BCx, BCy = cx - bx, cy - by
CAx, CAy = ax - cx, ay - cy
CBx, CBy = bx - cx, by - cy

# 어떤 패턴에 해당되는지 판정
pattern = 2
if BAx * BCx + BAy * BCy < 0:
	pattern = 1
if CAx * CBx + CAy * CBy < 0:
	pattern = 3

# 점과 직선의 거리 구하기
if pattern == 1:
	answer = math.sqrt(BAx ** 2 + BAy ** 2)
if pattern == 3:
	answer = math.sqrt(CAx ** 2 + CAy ** 2)
if pattern == 2:
	S = abs(BAx * BCy - BAy * BCx)
	BCLength = math.sqrt(BCx ** 2 + BCy ** 2)
	answer = S / BCLength

# 답 출력
print("{:.12f}".format(Answer))
