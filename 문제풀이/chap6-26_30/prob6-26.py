# numpy 라이브러리에 행렬의 T 제곱을 구하는 함수가 있습니다.
# 이를 활용하면, 다음과 같이 간단하게 코드를 구현할 수 있습니다.
# 물론 반복제곱법을 사용해서도 풀 수 있습니다. 이와 관련된 내용은 코드 4.7.1 등을 참고해주세요.

import numpy as np

Q = int(input())
for i in range(Q):
	S = input().split()
	X, Y, Z, T = float(S[0]), float(S[1]), float(S[2]), int(S[3])
	A = np.array([[ 1 - X, Y, 0 ], [ 0, 1 - Y, Z ], [ X, 0, 1 - Z ]])
	answer = np.linalg.matrix_power(A, T)
	print("{:.15f} {:.15f} {:.15f}".format(sum(answer[0]), sum(answer[1]), sum(answer[2])))