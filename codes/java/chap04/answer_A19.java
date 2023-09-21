import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int W = sc.nextInt();
		int[] w = new int[N + 1];
		int[] v = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}

		// 배열 dp 정의 및 초기화
		long[][] dp = new long[N + 1][W + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= W; j++) dp[i][j] = -1000000000000L;
		}

		// 동적 계획 알고리즘
		dp[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= W; j++) {
				if (j < w[i]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}

		// 출력
		long Answer = 0;
		for (int i = 0; i <= W; i++) Answer = Math.max(Answer, dp[N][i]);
		System.out.println(Answer);
	}
};
