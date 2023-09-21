# 입력
S = input()

# 왼쪽부터 순서대로 살펴본다
# 문자열은 0번째 문자부터 시작한다는 점에 유의하세요.
Stack = []
for i in range(len(S)):
	if S[i] == '(':
		Stack.append(i + 1)
	if S[i] == ')':
		print(Stack.pop(), i + 1)
