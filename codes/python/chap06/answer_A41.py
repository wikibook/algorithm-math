# 입력
N = int(input())
S = input()

# 답을 구한다
Answer = False
for i in range(0, N-2):
	if S[i] == 'R' and S[i+1] == 'R' and S[i+2] == 'R':
		Answer = True
	if S[i] == 'B' and S[i+1] == 'B' and S[i+2] == 'B':
		Answer = True

# 출력
if Answer == True:
	print("Yes")
else:
	print("No")
