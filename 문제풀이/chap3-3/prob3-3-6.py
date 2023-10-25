# 입력
N = int(input())
A = list(map(int, input().split()))

# 답 구하기
cnt = [0 for i in range(100000)]
for i in range(N):
	cnt[A[i]] += 1

Answer = 0
for i in range(1, 50000):
	Answer += cnt[i] * cnt[100000 - i]
Answer += cnt[50000] * (cnt[50000] - 1) // 2

# 출력
print(Answer)