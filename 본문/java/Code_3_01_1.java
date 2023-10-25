import java.util.*;

class Code_3_01_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		boolean answer = isPrime(N);
		if (answer == true) {
			System.out.println("prime");
		}
		else {
			System.out.println("not prime");
		}
	}
	static boolean isPrime(long N) {
		// 2 이상의 정수 N을 매개변수로 받고, N이 소수라면 True를,
		// 아니라면 False를 리턴하는 함수
		for (long i = 2; i <= N - 1; i++) {
			if (N % i == 0) {
				return false; // N이 i으로 나누어지는 경우, 이 시점에서 소수가 아니라는 것을 알 수 있음
			}
		}
		return true;
	}
}
