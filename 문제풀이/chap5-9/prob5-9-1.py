# 입력
N = int(input())
Answer = 0

# 10000원으로 지불
Answer += (N // 10000)
N %= 10000

# 5000원으로 지불
Answer += (N // 5000)
N %= 5000

# 1000원으로 지불
Answer += (N // 1000)
N %= 1000

# 출력
print(Answer)