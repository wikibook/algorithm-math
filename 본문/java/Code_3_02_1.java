import java.util.*;

class Code_3_02_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		System.out.println(GCD(A, B));
	}
	static long GCD(long A, long B) {
		// 양의 정수 A와 B의 최대 공약수를 리턴하는 함수
		// GCD는 Greatest Common Divisor(최대 공약수)의 약자
		long ans = 0;
		for (long i = 1; i <= A && i <= B; i++) {
			if (A % i == 0 && B % i == 0) {
				ans = i;
			}
		}
		return ans;
	}
}
