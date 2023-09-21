# 입력
N = int(input())

# 엘라토스테네스의 체
# 정수 x가 지워진 경우에 한해 Deleted[x]=true
Deleted = [ False ] * 1000009
LIMIT = int(N ** 0.5)
for i in range(2, LIMIT+1):
	if Deleted[i] == False:
		for j in range(i*2, N+1, i):
			Deleted[j] = True

# 답을 출력
for i in range(2, N+1):
	if Deleted[i] == False:
		print(i)
