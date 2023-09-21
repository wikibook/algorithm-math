import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int W = sc.nextInt();
		int L = sc.nextInt();
		int R = sc.nextInt();
		int[] X = new int[N + 2];
		for (int i = 1; i <= N; i++) {
			X[i] = sc.nextInt();
		}

		// 서쪽 끝을 징검다리 0, 동쪽 끝을 징검다리 N+1로 간주한다
		X[0] = 0;
		X[N + 1] = W;

		// 동적 계획 알고리즘
		final int MOD = 1000000007;
		int[] dp = new int[N + 2];
		int[] sum = new int[N + 2];
		dp[0] = 1;
		sum[0] = 1;
		for (int i = 1; i <= N + 1; i++) {
			int posL = lowerBound(X, X[i] - R);
			int posR = lowerBound(X, X[i] - L + 1) - 1;
			// dp[i]의 값을 누적 합으로 계산(뺄셈 한 뒤 나머지를 구하는 것에 주의!)
			dp[i] += (posR >= 0 ? sum[posR] : 0);
			dp[i] -= (posL >= 1 ? sum[posL - 1] : 0);
			dp[i] = (dp[i] + MOD) % MOD;
			// 누적 합 sum[i]를 업데이트
			sum[i] = sum[i - 1] + dp[i];
			sum[i] %= MOD;
		}

		// 출력
		System.out.println(dp[N + 1]);
	}

	// 정렬된 배열 A[0], A[1], ..., A[N-1], ... , A[N-1]에 대해, A[i] >= X가 되는 최소 i를 구하는 함수
	static int lowerBound(int[] A, int X) {
		int l = -1, r = A.length;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (A[m] >= X) {
				r = m;
			}
			else {
				l = m;
			}
		}
		return r;
	}
}