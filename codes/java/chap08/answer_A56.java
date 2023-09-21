import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		String S = sc.next();
		int[] a = new int[Q + 1];
		int[] b = new int[Q + 1];
		int[] c = new int[Q + 1];
		int[] d = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
			d[i] = sc.nextInt();
		}

		// 문자열 해시 준비
		StringHash Z = new StringHash(S);

		// 쿼리에 답한다
		for (int i = 1; i <= Q; i++) {
			long hash1 = Z.hashValue(a[i], b[i]);
			long hash2 = Z.hashValue(c[i], d[i]);
			if (hash1 == hash2) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}

	// 문자열 해시를 구현한 클래스 StringHash
	static class StringHash {
		static final int MOD = 2147483647;
		long[] power100;
		long[] h;
		StringHash(String S) {
			int N = S.length();
			// 문자열을 숫자로 변환하기
			int[] T = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				T[i] = (int)(S.charAt(i - 1) - 'a') + 1;
			}
			// 100의 n 제곱(본문 중의 B^0, B^1, ...에 대응)을 먼저 계산한다
			power100 = new long[N + 1];
			power100[0] = 1;
			for (int i = 1; i <= N; i++) {
				power100[i] = power100[i - 1] * 100 % MOD;
			}
			// H[1], H[2], ... , H[N]을 사전 계산하기
			h = new long[N + 1];
			h[0] = 1;
			for (int i = 1; i <= N; i++) {
				h[i] = (h[i - 1] * 100 + T[i]) % MOD;
			}
		}
		// S[l, r]의 해시값을 반환하는 함수
		// 나머지 계산에 주의!(5.3절)
		long hashValue(int l, int r) {
			long val = h[r] - h[l - 1] * power100[r - l + 1] % MOD;
			if (val < 0) {
				val += MOD;
			}
			return val;
		}
	}
}