# 뤼카 정리로 ncr mod 3 계산
def ncr(n, r):
	if n < 3 and r < 3:
		A = [
			[ 1, 0, 0 ],
			[ 1, 1, 0 ],
			[ 1, 2, 1 ]
		]
		return A[n][r]
	return ncr(n // 3, r // 3) * ncr(n % 3, r % 3) % 3

# 입력
N = int(input())
C = input()

# 답 구하기
answer = 0
for i in range(N):
	code = "BWR".find(C[i])
	answer += code * ncr(N - 1, i)
	answer %= 3

# 답에 (-1)^(N-1)을 곱함
if N % 2 == 0:
	answer = (3 - answer) % 3

# 답 출력("BWR"의 answer번째 문자)
print("BWR"[answer])