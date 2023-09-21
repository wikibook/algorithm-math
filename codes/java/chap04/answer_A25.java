import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력(배열 c는 0번부터 시작한다는 점에 유의하세요!)
		int H = sc.nextInt();
		int W = sc.nextInt();
		String[] c = new String[H];
		for (int i = 0; i < H; i++) c[i] = sc.next();

		// 동적 계획 알고리즘
		long[][] dp = new long[H][W];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
					if (i >= 1 && c[i - 1].charAt(j) == '.') dp[i][j] += dp[i - 1][j];
					if (j >= 1 && c[i].charAt(j - 1) == '.') dp[i][j] += dp[i][j - 1];
				}
			}
		}

		// 출력
		System.out.println(dp[H-1][W-1]);
	}
};
