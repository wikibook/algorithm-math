# 입력
N = int(input())
A = list(map(int, input().split()))
 
# 개수를 센다
cnt = [ 0 ] * 100
for i in range(N):
	cnt[A[i] % 100] += 1
 
# 답을 구한다
Answer = 0
for i in range(1, 50):
	Answer += cnt[i] * cnt[100-i]
Answer += cnt[0] * (cnt[0] - 1) // 2
Answer += cnt[50] * (cnt[50] - 1) // 2
 
# 출력
print(Answer)
