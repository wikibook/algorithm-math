# 이 코드의 복잡도는 O(N)입니다(5.7절의 테크닉 활용).

N = int(input())
Answer = 0

for i in range(1, N+1):
	d = (N // i)
	Answer += i * (d * (d + 1) // 2)

print(Answer)