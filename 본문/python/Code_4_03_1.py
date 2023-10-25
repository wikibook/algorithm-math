r = 2.0 # √2를 구할 것이므로
a = 2.0 # 초깃값은 적당한 수를 할당합니다.
repeats = 5

for i in range(1, repeats + 1):
	# 점 (a, f(a))의 x 좌표와 y 좌표를 구합니다.
	japyo_x, japyo_y = a, a * a
	
	# 접선 식 y = jupseon_a * x + jupseon_b를 구합니다.
	jupseon_a = 2.0 * japyo_x
	jupseon_b = japyo_y - jupseon_a * japyo_x
	
	# 다음 a의 값 next_a를 구합니다.
	next_a = (r - jupseon_b) / jupseon_a
	print("Step #{}: a = {:.12f} -> {:.12f}".format(i, a, next_a))
	a = next_a
