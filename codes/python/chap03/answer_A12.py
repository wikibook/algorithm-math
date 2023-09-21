# 답이 x 이하인지 판정하고 Yes라면 true, No라면 false를 반환하는 함수
def check(x, N, K, A):
	sum = 0
	for i in range(N):
		sum += x // A[i] # 'x÷A[i]' 소수점 이하 자르기

	if sum >= K:
		return True
	return False

# 입력
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 바이너리 서치
# Left는 탐색 범위의 왼쪽 끝, Right는 탐색 범위의 오른쪽 끝을 나타낸다
Left = 1
Right = 10 ** 9
while Left < Right:
	Mid = (Left + Right) // 2
	Answer = check(Mid, N, K, A)

	if Answer == False:
		Left = Mid + 1 # 답이 Mid+1 이상임을 알 수 있다
	if Answer == True:
		Right = Mid # 답이 Mid 이하임을 알 수 있다

# 출력(이때, Left=Right가 된다)
print(Left)
