N = int(input())

answer = 0

# 10000원 이상이라면 10000원으로 지불할 수 있는 만큼 지불
while N >= 10000:
	N -= 10000
	answer += 1

# 5000원 이상이라면 5000원으로 지불할 수 있는 만큼 지불
while N >= 5000:
	N -= 5000
	answer += 1

# 남은 금액은 1000원으로 지불
while N >= 1:
	N -= 1000
	answer += 1

print(answer)
