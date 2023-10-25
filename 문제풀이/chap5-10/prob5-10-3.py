# 입력
A, B, C = map(int, input().split())

# 계산
mod = 998244353
D = A * (A + 1) // 2
E = B * (B + 1) // 2
F = C * (C + 1) // 2

# 답 출력
print((D * E * F) % mod)