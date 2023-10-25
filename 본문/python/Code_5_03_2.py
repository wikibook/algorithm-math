# 입력 → 배열 요소의 총합 S를 구함
N, K = map(int, input().split())
A = list(map(int, input().split()))
S = sum(A)

# 답 출력
if S % 2 != K % 2:
	print("No")
elif S > K:
	print("No")
else:
	print("Yes")
