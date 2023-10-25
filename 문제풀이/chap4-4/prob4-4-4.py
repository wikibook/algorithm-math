cnt = 0
LIMIT = 23 # 이를 30으로 변경하면, 답을 구할 수 있음
Current = 0

# 하나씩 더해 나감
while Current < LIMIT:
	cnt += 1
	Current += 1.0 / cnt

# 출력
print(cnt)