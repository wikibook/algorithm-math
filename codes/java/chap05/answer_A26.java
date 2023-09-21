import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int Q = sc.nextInt();
		int[] X = new int[Q + 1];
		for (int i = 1; i <= Q; i++) X[i] = sc.nextInt();

		// 출력
		for (int i = 1; i <= Q; i++) {
			boolean Answer = isPrime(X[i]);
			if (Answer == true) System.out.println("Yes");
			if (Answer == false) System.out.println("No");
		}
	}

	// x가 소수일 때 true, 소수가 아닐 때 false를 반환하는 함수
	static boolean isPrime(int x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) return false;
		}
		return true;
	}
};
