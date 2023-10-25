# 입력
N = int(input())

# 답 계산
Answer = 1
for i in range(1,N+1):
	Answer *= i

# 출력
print(Answer)