# 입력
N, D = map(int, input().split())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 배열 준비
# used[i]는 작업 i를 선택했는지 여부를 나타냅니다.
used = [ False ] * N

# 답을 구한다
Answer = 0
for i in range(1, D+1):
	maxValue = 0 # 급여의 최대치
	maxID = -1   # 월급이 최대가 되는 직업의 수
	for j in range(N):
		if used[j] == False and maxValue < Y[j] and X[j] <= i:
			maxValue = Y[j]
			maxID = j

	# 선택할 수 있는 직업이 있는 경우
	if maxID != -1:
		Answer += maxValue
		used[maxID] = True

# 출력
print(Answer)
