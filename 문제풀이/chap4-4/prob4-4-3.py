# 참고적으로 파이썬은 속도가 느리므로
# 알고리즘 테스트에서 시간 제한을 통과하지 못할 가능성이 있습니다.
# 이때는 알고리즘을 조금 수정한 "prob4-4-3_fast.py"를 참고해보세요.

# 입력
N = int(input())
F = [0 for i in range(N + 1)]

# F[1], F[2], ..., F[N]를 계산하기
for i in range(1, N + 1):
	# F[i], F[2i], F[3i], ...에 1을 추가
	for j in range(1, (N // i) + 1):
		F[j * i] += 1

# 답 구하기
Answer = 0
for i in range(1, N + 1):
	Answer += i * F[i]

# 출력
print(Answer)