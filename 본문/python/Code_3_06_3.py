def func(N):
	if N == 1:
		return 1  # 이처럼 재귀 함수를 끝내는 경우를 "베이스 케이스"라고 부릅니다.
	return func(N - 1) * N

N = int(input())
print(func(N))

# 파이썬은 함수를 호출과 관련된 스택 개수에 제한이 있습니다.
# 기본적으로는 1000이므로, 재귀적으로 함수를 1000번 호출하면 오류가 발생합 니다.
# 이 제한은 sys.getrecursionlimit()으로 확인할 수 있으며, sys.setrecursionlimit(depth)으로 변경할 수 있습니다.
# 추가적으로 이는 sys 모듈의 함수이므로, import sys로 모듈을 읽어 들여야 사용할 수 있습니다.
