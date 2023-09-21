# 입력
X, Y = map(int, input().split())

# 거꾸로 생각하기
Answer = []
while X>=2 or Y>=2:
	Answer.append([X, Y])
	if X > Y:
		X -= Y
	else:
		Y -= X
Answer.reverse()

# 출력
print(len(Answer))
for i in range(len(Answer)):
	print(str(Answer[i][0]) + ' ' + str(Answer[i][1]))
