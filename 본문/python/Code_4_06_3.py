MOD = 1000000007

a, b = map(int, input().split())

answer = 1  # a의 0은 1이므로, answer = 1로 초기화
for i in range(b):
	answer = (answer * a) % MOD

print(answer)
