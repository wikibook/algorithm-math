import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 배열 dp의 정의
		boolean[][] dp = new boolean[N + 1][S + 1];

		// 동적 계획 알고리즘（i = 0）
		dp[0][0] = true;
		for (int i = 1; i <= S; i++) dp[0][i] = false;

		// 동적 계획 알고리즘（i >= 1）
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= S; j++) {
				if (j < A[i]) {
					if (dp[i - 1][j] == true) dp[i][j] = true;
					else dp[i][j] = false;
				}
				if (j >= A[i]) {
					if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) dp[i][j] = true;
					else dp[i][j] = false;
				}
			}
		}

		// 출력
		if (dp[N][S] == true) System.out.println("Yes");
		else System.out.println("No");
	}
};
