import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] A = new int[H + 2][W + 2];
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) A[i][j] = Integer.parseInt(sc.next());
		}
		
		// 행의 총합 계산하기
		int[] gyou = new int[H + 2];
		for (int i = 1; i <= H; i++) {
			gyou[i] = 0;
			for (int j = 1; j <= W; j++) gyou[i] += A[i][j];
		}
		
		// 열의 총합 계산하기
		int[] retu = new int[W + 2];
		for (int j = 1; j <= W; j++) {
			retu[j] = 0;
			for (int i = 1; i <= H; i++) retu[j] += A[i][j];
		}
		
		// 각 칸의 답 계산하기
		int[][] Answer = new int[H + 2][W + 2];
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				Answer[i][j] = gyou[i] + retu[j] - A[i][j];
			}
		}
		
		// 공백으로 구분해서 출력하기
		StringBuilder ans = new StringBuilder();
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (j != 1) ans.append(' ');
				ans.append(Answer[i][j]);
			}
			ans.append('\n');
		}
		System.out.println(ans.toString());
	}
}