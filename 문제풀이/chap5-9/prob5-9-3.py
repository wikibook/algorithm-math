# 입력
# A는 (종료 시각, 시작 시각) 형태이므로 주의하기(종료 시각 순서로 쉽게 정렬하려고 이런 형태로 만듦)
N = int(input())
A = []
for i in range(N):
	a, b = map(int, input().split())
	A.append([b, a])

# 정렬
A.sort()

# 종료 시각이 가장 빠른 것 선택하기를 반복함
CurrentTime = 0
Answer = 0
for i in range(N):
	if CurrentTime <= A[i][1]:
		CurrentTime = A[i][0]
		Answer += 1

# 출력
print(Answer)