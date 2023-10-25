def func(N):
	# func(N) → func(N-1) → ... → 
	# func(0) → func(-1) → func(-2) → ...처럼 무한하게 호출되어서
	# 프로그램이 정상적으로 작동하지 않습니다.
	return func(N - 1) * N

N = int(input())
print(func(N))
