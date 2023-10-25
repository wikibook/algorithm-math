# 작은 문제 t를 푸는 함수
def small_problem(A, B, t):
	cl = (A + t - 1) // t  # A÷t의 소수점 아래를 자릅니다.
	cr = B // t  # B÷t의 소수점 아래를 자릅니다.
	if cr - cl >= 1:
		return True
	else:
		return False

A, B = map(int, input().split())
for i in range(1, B + 1):
	if small_problem(A, B, i) == True:
		answer = i
print(answer)
