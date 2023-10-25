import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 답 계산
		final long MOD = 1000000007;
		long V = modpow(4, N + 1, MOD) - 1;
		long Answer = division(V, 3, MOD);
		
		// 출력
		System.out.println(Answer);
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