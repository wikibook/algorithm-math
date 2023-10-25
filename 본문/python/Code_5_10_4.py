# 입력
N = int(input())
S = input()

# (의 수에서 )의 수를 뺀 값을 depth에 할당합니다.
# 중간에 depth가 음수가 된다면, 곧바로 답이 No입니다.
depth = 0
flag = True
for i in range(N):
	if S[i] == '(':
		depth += 1
	if S[i] == ')':
		depth -= 1
	if depth < 0:
		flag = False

# 마지막으로 depth = 0[(와 )의 수가 같음]을 추가적으로 판정합니다.
if flag == True and depth == 0:
	print("Yes")
else:
	print("No")
