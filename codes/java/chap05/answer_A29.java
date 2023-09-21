import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		long a = sc.nextLong();
		long b = sc.nextLong();

		// 출력(Answer는 현재 칠판의 수)
		System.out.println(Power(a, b, 1000000007));
	}

	// a의 b제곱을 m으로 나눈 나머지를 반환하는 함수
	// 변수 p는 a^1 → a^2 → a^4 → a^8 → a^16 → ･･･으로 변화
	static long Power(long a, long b, long m) {
		long p = a, Answer = 1;
		for (int i = 0; i < 30; i++) {
			int wari = (1 << i);
			if ((b / wari) % 2 == 1) {
				Answer = (Answer * p) % m; // 'a의 2i승'을 곱할 때
			}
			p = (p * p) % m;
		}
		return Answer;
	}
};
