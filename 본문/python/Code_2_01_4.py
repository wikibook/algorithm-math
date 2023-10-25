N = int(input()) # 입력 부분
answer = ""

while N >= 1:
	# N % 2는 N를 2로 나눈 나머지(예: N = 13의 경우 1)
	# N // 2는 N를 2로 나눈 때의 정수 부분(몫)(예: N = 13의 경우 6)
	if N % 2 == 0:
		answer = "0" + answer
	if N % 2 == 1:
		answer = "1" + answer
	N = N // 2

print(answer) # 출력 부분
