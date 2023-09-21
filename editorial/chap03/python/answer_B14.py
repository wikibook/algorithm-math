import bisect
import sys

# "배열 A에 있는 카드 중 몇 개를 선택했을 때의 합계"로 생각되는 것을 열거한다
# 비트 완전 탐색 사용
def Enumerate(A):
	SumList = []
	for i in range(2 ** len(A)):
		sum = 0 # 현재 합계 값
		for j in range(len(A)):
			wari = (2 ** j)
			if (i // wari) % 2 == 1:
				sum += A[j]
		SumList.append(sum)
	return SumList

# 입력
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 카드를 반으로 나눈다
L1 = A[0:(N//2)]
L2 = A[(N//2):N]

# 각각에 대해 '가능한 카드의 합계'를 모두 열거한다
Sum1 = Enumerate(L1)
Sum2 = Enumerate(L2)
Sum1.sort()
Sum2.sort()

# 바이너리 서치에서 Sum1[i] + Sum2[j] = K가 되는 것이 존재하는지 찾기
for i in range(len(Sum1)):
	pos = bisect.bisect_left(Sum2, K-Sum1[i])
	if pos<len(Sum2) and Sum2[pos]==K-Sum1[i]:
		print("Yes")
		sys.exit(0)

# 발견하지 못한 경우
print("No")
