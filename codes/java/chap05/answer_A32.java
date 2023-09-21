import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();

		// 승자를 계산한다
		boolean[] dp = new boolean[N + 1];
		for (int i = 0; i <= N; i++) {
			if (i >= A && dp[i-A] == false) dp[i] = true; // 승리 상태
			else if (i >= B && dp[i-B] == false) dp[i] = true; // 승리 상태
			else dp[i] = false; // 패배 상태
		}

		// 출력
		if (dp[N] == true) System.out.println("First");
		else System.out.println("Second");
	}
};
