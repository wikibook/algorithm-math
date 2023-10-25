# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 계산
Answer = 0
for i in range(N):
    Answer += A[i]

# 출력
print(Answer % 100)
