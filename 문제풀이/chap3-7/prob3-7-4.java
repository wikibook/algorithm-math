import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 배열 초기화
		boolean[][] dp = new boolean[N + 1][S + 1];
		dp[0][0] = true;
		for (int i = 1; i <= S; i++) {
			dp[0][i] = false;
		}
		
		// 동적계획법
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= S; j++) {
				if (j < A[i]) {
					// j < A[i]라면, 카드 i를 선택할 수 없음
					dp[i][j] = dp[i - 1][j];
				}
				else {
					// j >= A[i]라면, 선택/선택하지 않음이라는 선택지가 있음
					if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = false;
					}
				}
			}
		}
		
		// 답을 계산하고 출력
		if (dp[N][S] == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}