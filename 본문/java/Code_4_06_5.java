import java.util.*;

class Code_4_06_5 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		// 이항계수의 분자와 분모 구하기(과정1 / 과정2)
		final long MOD = 1000000007;
		long bunja = 1, bunmo = 1;
		for (int i = 1; i <= X + Y; i++) {
			bunja = (bunja * i) % MOD;
		}
		for (int i = 1; i <= X; i++) {
			bunmo = (bunmo * i) % MOD;
		}
		for (int i = 1; i <= Y; i++) {
			bunmo = (bunmo * i) % MOD;
		}
		
		// 답 구하기(과정3)
		long answer = division(bunja, bunmo, MOD);
		System.out.println(answer);
	}
	static long modpow(long a, long b, long m) {
		// 반복제곱법(p에는 a^1, a^2, a^4, a^8, ...가 할당됨)
		long p = a, answer = 1;
		for (int i = 0; i < 30; i++) {
			if ((b & (1 << i)) != 0) {
				answer = (answer * p) % m;
			}
			p = (p * p) % m;
		}
		return answer;
	}
	static long division(long a, long b, long m) {
		// division(a, b, m)은 a÷b mod m를 리턴하는 함수
		return (a * modpow(b, m - 2, m)) % m;
	}
}
