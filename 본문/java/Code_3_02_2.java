import java.util.*;

class Code_3_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		System.out.println(GCD(A, B));
	}
	static long GCD(long A, long B) {
		// 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
		// GCD는 Greatest Common Divisor(최대 공약수)의 약자
		while (A >= 1 && B >= 1) {
			if (A < B) {
				B %= A; // A < B라면, 큰 수를 b로 변경합니다.
			}
			else {
				A %= B; // A >= B라면 큰 수를 a로 변경합니다.
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
}
