import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 답 구하기
		long mod = 1000000007;
		long val = N * (N + 1) / 2;
		val %= mod;
		System.out.println(val * val % mod);
	}
}