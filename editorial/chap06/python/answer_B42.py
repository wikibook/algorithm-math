# omote=1일 때 앞면의 합계가 양수, ura=1일 때 뒤쪽의 합계가 양수
# omote=2일 때 앞면의 합계가 음수, ura=2일 때 뒤쪽의 합계가 음수
def solve(omote, ura, A, B):
	sum = 0
	for i in range(N):
		card1 = A[i]
		if omote == 2:
			card1 = -A[i]
		card2 = B[i]
		if ura == 2:
			card2 = -B[i]
		# 카드 i를 선택해야 할까?
		if card1 + card2 >= 0:
			sum += (card1 + card2)
	return sum

# 입력
N = int(input())
A = [ None ] * N
B = [ None ] * N
for i in range(N):
	A[i], B[i] = map(int, input().split())

# 앞의 총합의 양과 음, 뒤의 총합의 양과 음을 완벽 탐색
Answer1 = solve(1, 1, A, B);
Answer2 = solve(1, 2, A, B);
Answer3 = solve(2, 1, A, B);
Answer4 = solve(2, 2, A, B);

# 출력
print(max(Answer1, Answer2, Answer3, Answer4))
