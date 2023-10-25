# 입력(배열B의 인덱스가 0부터 시작하므로 주의)
N = int(input())
B = list(map(int, input().split()))

# 수열A의 요소 합계 구하기
answer = B[0] + B[N - 2]
for i in range(1, N - 1):
	answer += min(B[i - 1], B[i])

# 답 출력
print(answer)