import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextLong();
		}
		
		// 2^i 구하기
		final long mod = 1000000007;
		long[] power = new long[N + 1];
		power[0] = 1;
		for (int i = 1; i <= N; i++) {
			power[i] = (2 * power[i - 1]) % mod;
		}
		
		// 답 구하기
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += power[i - 1] * A[i];
			Answer %= mod;
		}
		
		// 출력
		System.out.println(Answer);
	}
}