import java.util.*;

class Code_2_02_1 {
	public static void main(String[] args) {
		// 사칙 연산
		System.out.println(869 + 120); // 989
		System.out.println(869 - 120); // 749
		System.out.println(869 * 120); // 104280
		System.out.println(869 / 120); // 7(정수끼리 나누는 경우, 소수점 아래가 포함되지 않으므로 주의하기)
		
		// 나머지(mod)
		System.out.println(8 % 5); // 3
		System.out.println(869 % 120); // 29
		
		// 절댓값(abs)
		System.out.println(Math.abs(-45)); // 45
		System.out.println(Math.abs(15)); // 15
		
		// 제곱 (pow)
		System.out.println((int)Math.pow(10.0, 2.0)); // 100
		System.out.println((int)Math.pow(3.0, 4.0)); // 81
		
		// 루트(sqrt)
		System.out.format("%.5f\n", Math.sqrt(4.0)); // 2.00000
		System.out.format("%.5f\n", Math.sqrt(2.0)); // 1.41421
	}
};
