import sys

# 입력
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 배열 초기화
First = [-1 for i in range(N+1)]
Second = [-1 for i in range(N+1)]

# 답 구하기
# cur은 현재 있는 마을의 번호
cnt = 0
cur = 1
while True:
	# First, Second 변경
	if First[cur] == -1:
		First[cur] = cnt
	elif Second[cur] == -1:
		Second[cur] = cnt
	
	# K회 이동 후에 마을 cur에 있는지 판정
	if cnt == K:
		print(cur)
		sys.exit()
	elif Second[cur] != -1 and (K - First[cur]) % (Second[cur] - First[cur]) == 0:
		print(cur)
		sys.exit()
	
	cur = A[cur - 1]
	cnt += 1