Map = {}
 
# 입력
N = int(input())
A = [int(input()) for _ in range(N)]

# 답을 구한다
Answer = 0
for a in A:
	# dict.get에는 키가 존재하지 않는 경우의 기본값을 설정할 수 있다
	Answer += Map.get(a, 0)
	Map[a] = Map.get(a, 0) + 1

# 출력
print(Answer)
