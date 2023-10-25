import java.util.*;

class Code_4_03_1 {
	public static void main(String[] args) {
		double r = 2.0; // √2를 구할 것이므로
		double a = 2.0; // 초깃값은 적당한 수를 할당합니다.
		for (int i = 1; i <= 5; i++) {
			// 점 (a, f(a))의 x 좌표와 y 좌표를 구합니다.
			double japyo_x = a;
			double japyo_y = a * a;
			
			// 접선 식 y = jupseon_a * x + jupseon_b를 구합니다.
			double jupseon_a = 2.0 * japyo_x;
			double jupseon_b = japyo_y - jupseon_a * japyo_x;
			
			// 다음 a의 값 next_a를 구합니다.
			double next_a = (r - jupseon_b) / jupseon_a;
			System.out.format("Step #%d: a = %.12f -> %.12f\n", i, a, next_a);
			a = next_a;
		}
	}
}
