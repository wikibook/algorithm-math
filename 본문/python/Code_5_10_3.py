# 입력
N, X, Y = map(int, input().split())

# 4개의 정수 (a, b, c, d)를 전체 탐색
flag = False
for a in range(1, N + 1):
	for b in range(a, N + 1):
		for c in range(b, N + 1):
			for d in range(c, N + 1):
				if a + b + c + d == X and a * b * c * d == Y:
					flag = True  # 답을 찾았다면 flag를 True로 변경합니다.

# 답 출력
if flag == True:
	print("Yes")
else:
	print("No")

# 파이썬 등의 실행 속도가 느린 프로그래밍 언어는 {N+3}_C_4가지 탐색하는 방법으로도
# 실행 시간 제한을 맞추지 못할 수 있습니다. 
# 따라서 O(N)으로 푸는 방법을 활용해야 할 수 있습니다.
# 이와 관련된 내용은 Code_5_10_3_extra.py를 참고해 주세요.