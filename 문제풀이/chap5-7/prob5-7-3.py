# 입력
N = int(input())
A = list(map(int, input().split()))

# 배열A 전체를 정렬
A.sort()

# 답 구하기
Answer = 0
for i in range(1, N + 1):
	Answer += A[i - 1] * (-N + 2 * i - 1)

# 출력
print(Answer)