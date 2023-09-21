import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 동적 계획 알고리즘(N 단계)
		int[][] dp = new int[N + 1][N + 1];
		for (int j = 1; j <= N; j++) dp[N][j] = A[j];

		// 동적 계획 알고리즘 [ 1 ~ N-1번째 층 ]
		for (int i = N - 1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				if (i % 2 == 1) dp[i][j] = Math.max(dp[i+1][j], dp[i+1][j+1]);
				if (i % 2 == 0) dp[i][j] = Math.min(dp[i+1][j], dp[i+1][j+1]);
			}
		}

		// 출력
		System.out.println(dp[1][1]);
	}
};
