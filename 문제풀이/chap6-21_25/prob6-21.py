import math

r = 2.0 # y = e^x과 y = 2의 교점을 구할 것이므로
a = 1.0 # 초깃값을 적당하게 1.0으로 설정
repeats = 5

for i in range(1, repeats + 1):
	# 점 (a, f(a))의 x 좌표와 y 좌표를 구합니다.
	japyo_x, japyo_y = a, math.exp(a)
	
	# 접선 식 y = jupseon_a * x + jupseon_b를 구합니다.
	jupseon_a = japyo_y
	jupseon_b = japyo_y - jupseon_a * japyo_x
	
	# 다음 a의 값 next_a를 구합니다.
	next_a = (r - jupseon_b) / jupseon_a
	print("Step #{}: a = {:.15f}-> {:.15f}".format(i, a, next_a))
	a = next_a