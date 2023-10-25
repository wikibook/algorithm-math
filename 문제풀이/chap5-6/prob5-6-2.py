# 입력
N = int(input())
A = list(map(int, input().split()))

# 2^i 구하기
mod = 1000000007
power = [0 for i in range(N)]
power[0] = 1
for i in range(1, N):
	power[i] = (2 * power[i - 1]) % mod

# 답 구하기
Answer = 0
for i in range(N):
	Answer += power[i] * A[i]
	Answer %= mod

# 출력
print(Answer)