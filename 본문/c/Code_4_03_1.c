#include <stdio.h>

int main() {
	double r = 2.0; // √2를 구할 것이므로
	double a = 2.0; // 초깃값은 적당한 수를 할당합니다.
	int i;
	for (i = 1; i <= 5; i++) {
		// 점 (a, f(a))의 x 좌표와 y 좌표를 구합니다.
		double japyo_x = a;
		double japyo_y = a * a;

		// 접선의 기울기 구하기[y = (jupseon_a)x + jupseon_b]
		double jupseon_a = 2.0 * japyo_x;
		double jupseon_b = japyo_y - jupseon_a * japyo_x;

		// 다음 a의 값 next_a를 구합니다.
		double next_a = (r - jupseon_b) / jupseon_a;
		printf("Step #%d: a = %.12lf -> %.12lf\n", i, a, next_a);
		a = next_a;
	}
	return 0;
}
