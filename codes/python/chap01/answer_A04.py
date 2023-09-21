# 입력
N = int(input())

# 윗자리부터 순서대로 '2진법으로 변환한 값'을 구한다
for x in [9,8,7,6,5,4,3,2,1,0]:
	wari = (2 ** x)
	print((N // wari) % 2, end='')

# 마지막에 줄바꿈한다
print("")
