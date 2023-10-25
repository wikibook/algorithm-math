# 입력
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = [0 for i in range(M)]
for i in range(M):
	B[i] = int(input())

# 누적합 구하기
S = [0 for i in range(N)]
for i in range(1, N):
	S[i] = S[i - 1] + A[i - 1]

# 답 구하기
# B[i] - 1 등으로 되는 이유는 배열의 인덱스가 0부터 시작하기 때문입니다.
Answer = 0
for i in range(M-1):
	if B[i] < B[i + 1]:
		Answer += S[B[i + 1] - 1] - S[B[i] - 1]
	else:
		Answer += S[B[i] - 1] - S[B[i + 1] - 1]

# 출력
print(Answer)