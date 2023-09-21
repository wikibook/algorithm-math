# 입력
N = int(input())
A = list(map(int, input().split()))

# 개수를 센다
cnt = [ 0 ] * 101
Answer = 0
for i in range(N):
	cnt[A[i]] += 1

# 답을 구한다
for i in range(1, 101):
	Answer += cnt[i] * (cnt[i]-1) * (cnt[i]-2) // 6;
print(Answer)
