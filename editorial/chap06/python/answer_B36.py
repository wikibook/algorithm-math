# 입력
N, K = map(int, input().split())
S = input()

# ON으로 되어 있는 것의 개수를 센다
numON = 0
for i in range(N):
	if S[i] == '1':
		numON += 1

# 답을 출력
if numON%2 == K%2:
	print("Yes")
else:
	print("No")
