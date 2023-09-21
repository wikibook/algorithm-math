import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] A = new int[M + 1][N + 1];
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) A[i][j] = sc.nextInt();
		}

		// 배열 초기화
		int[][] dp = new int[M + 1][1 << N];
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j < (1 << N); j++) dp[i][j] = 1000000000;
		}

		// 동적 계획 알고리즘
		dp[0][0] = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < (1 << N); j++) {
				// already[k] = 1일 때, 물품 k는 이미 무료 상태다
				int[] already = new int[N + 1];
				for (int k = 1; k <= N; k++) {
					if ((j / (1 << (k - 1)) % 2) == 0) already[k] = 0;
					else already[k] = 1;
				}

				// 쿠폰 i를 선택한 경우의 정수 표현 v를 계산한다
				int v = 0;
				for (int k = 1; k <= N; k++) {
					if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
				}

				// 이동을 수행한다
				dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
				dp[i][v] = Math.min(dp[i][v], dp[i - 1][j] + 1);
			}
		}

		// 출력(모두 선택한 경우의 정수 표현은 2^N-1)
		if (dp[M][(1 << N) - 1] == 1000000000) System.out.println("-1");
		else System.out.println(dp[M][(1 << N) - 1]);
	}
};
