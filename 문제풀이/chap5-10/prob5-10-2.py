# 입력
N = int(input())

# 답 구하기
mod = 1000000007
val = N * (N + 1) // 2
print(val * val % mod)