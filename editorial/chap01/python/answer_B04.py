# 입력
N = input()

# 답을 구한다
Answer = 0
for i in range(len(N)):
	keta = 0
	kurai = (2 ** (len(N) - 1 - i))
	if N[i] == '1':
		keta = 1
	Answer += keta * kurai

# 출력
print(Answer)
