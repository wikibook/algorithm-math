import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		
		// 계산
		long mod = 998244353;
		long D = A * (A + 1) / 2; D %= mod;
		long E = B * (B + 1) / 2; E %= mod;
		long F = C * (C + 1) / 2; F %= mod;
		
		// 답 출력
		// 여기에서 (D * E * F) % mod로 해도, 중간에 10^27를 다루어야 할 수 있으므로
		// long long 자료형이라도 오버플로가 발생할 수 있으므로 주의
		System.out.println((D * E % mod) * F % mod);
	}
}