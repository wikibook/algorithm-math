import java.util.*;

class Code_4_06_6 {
	public static void main(String[] args) {
		// 배열 fact의 초깃값(fact[i]은 i 팩토리얼을 1000000007로 나눈 나머지)
		fact = new long[LIMIT + 1];
		fact[0] = 1;
		for (int i = 1; i <= LIMIT; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		
		// 입력 → 답 출력
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		System.out.println(ncr(X + Y, Y));
	}
	static final long MOD = 1000000007;
	static final int LIMIT = 200000;
	static long[] fact;
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
	static long ncr(int n, int r) {
		// ncr은 n!를 r! × (n-r)!으로 나눈 값
		return division(fact[n], fact[r] * fact[n - r] % MOD, MOD);
	}
}
