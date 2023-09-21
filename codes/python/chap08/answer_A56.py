# 입력
N, Q = map(int, input().split())
S = input()
queries = [ list(map(int, input().split())) for i in range(Q) ]

# 문자를 숫자로 변환(여기서는 책과 달리 0-indexed로 구현했다)
# ord(c)로 문자 c의 문자 코드(ASCII 코드)를 얻는다.
T = list(map(lambda c: ord(c) - ord('a') + 1, S))

# 100의 n 제곱을 사전 계산
MOD = 2147483647
power100 = [ None ] * (N + 1)
power100[0] = 1
for i in range(N):
	power100[i + 1] = power100[i] * 100 % MOD

# H[1], H[2], ..., H[N] 계산하기
H = [ None ] * (N + 1)
H[0] = 0
for i in range(N):
	H[i + 1] = (H[i] * 100 + T[i]) % MOD

# 해시값 구하는 함수
# S[l-1:r]의 해시값은 (H[r] - H[l - 1] * power100[r - l + 1]) % MOD 로 계산
# C++과 달리 (음수) % M (M >= 1)도 0 이상 M-1 이하가 될 수 있음에 주의
def hash_value(l, r):
	return (H[r] - H[l - 1] * power100[r - l + 1]) % MOD

# 쿼리에 답한다
for a, b, c, d in queries:
	hash1 = hash_value(a, b)
	hash2 = hash_value(c, d)
	if hash1 == hash2:
		print("Yes")
	else:
		print("No")
