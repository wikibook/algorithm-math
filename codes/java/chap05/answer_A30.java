import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		long n = sc.nextLong();
		long r = sc.nextLong();

		// 순서 1: 분자 a를 구한다
		long M = 1000000007;
		long a = 1;
		for (int i = 1; i <= n; i++) a = (a * i) % M;

		// 순서 2: 분모 b를 구한다
		long b = 1;
		for (int i = 1; i <= r; i++) b = (b * i) % M;
		for (int i = 1; i <= n - r; i++) b = (b * i) % M;

		// 순서 3: 답을 구한다
		System.out.println(Division(a, b, M));
	}

	// a의 b제곱을 m으로 나눈 나머지를 반환하는 함수
	static long Power(long a, long b, long m) {
		long p = a, Answer = 1;
		for (int i = 0; i < 30; i++) {
			int wari = (1 << i);
			if ((b / wari) % 2 == 1) {
				Answer = (Answer * p) % m;
			}
			p = (p * p) % m;
		}
		return Answer;
	}

	// a ÷ b를 m으로 나눈 나머지를 반환하는 함수
	static long Division(long a, long b, long m) {
		return (a * Power(b, m - 2, m)) % m;
	}
};
