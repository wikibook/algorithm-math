import java.util.*;

class Code_3_07_1 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] H = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			H[i] = sc.nextInt();
		}
		
		// 동적계획법
		int[] dp = new int[N + 1];
		dp[1] = 0;
		for (int i = 2; i <= N; i++) {
			if (i == 2) {
				dp[i] = Math.abs(H[i - 1] - H[i]);
			}
			if (i >= 3) {
				int v1 = dp[i - 1] + Math.abs(H[i - 1] - H[i]); // 1개 이전 발판에서 점프할 때
				int v2 = dp[i - 2] + Math.abs(H[i - 2] - H[i]); // 2개 이전 발판에서 점프할 때
				dp[i] = Math.min(v1, v2);
			}
		}
		
		// 답 출력
		System.out.println(dp[N]);
	}
}
