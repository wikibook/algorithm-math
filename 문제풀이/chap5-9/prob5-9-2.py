# 입력
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 배열 A, B 정렬하기
A.sort()
B.sort()

# 답 구하기
Answer = 0
for i in range(N):
	Answer += abs(A[i] - B[i])

# 출력
print(Answer)