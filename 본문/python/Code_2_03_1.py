cnt = 1000

def func1():
	return 2021

def func2(pos):
	global cnt # 전역 변수 cnt를 함수 내부에서 사용
	cnt += 1
	return cnt + pos

print(func1()) # "2021"이라고 출력
print(func2(500)) # "1501"이라고 출력
print(func2(500)) # "1502"라고 출력
