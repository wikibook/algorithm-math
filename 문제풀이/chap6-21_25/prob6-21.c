#include <math.h>
#include <stdio.h>

int main() {
	double r = 2.0; // y = e^x과 y = 2의 교점을 구할 것이므로
	double a = 1.0; // 초깃값을 적당하게 1.0으로 설정
	int i;
	for (i = 1; i <= 5; i++) {
		// 점 (a, f(a))의 x 좌표와 y 좌표를 구합니다.
		double japyo_x = a;
		double japyo_y = exp(a);

		// 접선의 기울기 구하기[y = (jupseon_a)x + jupseon_b]
		double jupseon_a = japyo_y;
		double jupseon_b = japyo_y - jupseon_a * japyo_x;

		// 다음 a의 값 next_a를 구합니다.
		double next_a = (r - jupseon_b) / jupseon_a;
		printf("Step #%d: a = %.15lf -> %.15lf\n", i, a, next_a);
		a = next_a;
	}
	return 0;
}