# 입력
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 배열 정렬(A는 오름차순, B는 내림차순으로 정렬)
A.sort()
B.sort(reverse = True)

# 답은 A[i] * B[i]의 합계
print(sum([ A[i] * B[i] for i in range(N) ]))