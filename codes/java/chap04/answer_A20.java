import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력(문자열은 0번째 문자부터 시작하는 것에 주의!)
		String S = sc.next(); int N = S.length();
		String T = sc.next(); int M = T.length();

		// 배열 dp의 정의
		int[][] dp = new int[N + 1][M + 1];

		// 동적 계획 알고리즘
		dp[0][0] = 0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				if (i >= 1 && j >= 1 && S.charAt(i-1) == T.charAt(j-1)) {
					dp[i][j] = Math.max(dp[i - 1][j], Math.max(dp[i][j - 1], dp[i - 1][j - 1] + 1));
				}
				else if (i >= 1 && j >= 1) {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
				else if (i >= 1) {
					dp[i][j] = dp[i - 1][j];
				}
				else if (j >= 1) {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}

		// 출력
		System.out.println(dp[N][M]);
	}
};
