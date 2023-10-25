import java.util.*;

class Code_3_01_2 {
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
		for (long i = 2; i * i <= N; i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}
}
