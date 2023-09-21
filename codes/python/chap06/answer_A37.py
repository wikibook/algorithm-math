# 입력
N, M, B = map(int, input().split())
A = list(map(int, input().split()))
C = list(map(int, input().split()))

# 답 계산
Answer = 0
for i in range(N):
	Answer += A[i] * M
Answer += B * N * M
for j in range(M):
	Answer += C[j] * N

# 출력
print(Answer)
