import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] P = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				P[i][j] = sc.nextInt();
			}
		}

		// '낙상 횟수를 구하는 문제'를 2가지로 분해한다
		int[] X = new int[N + 1];
		int[] Y = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (P[i][j] != 0) {
					X[i] = P[i][j];
					Y[j] = P[i][j];
				}
			}
		}

		// X의 전도 수, Y의 전도 수를 구한다
		int inversionX = 0;
		int inversionY = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (X[i] > X[j]) {
					inversionX += 1;
				}
				if (Y[i] > Y[j]) {
					inversionY += 1;
				}
			}
		}

		// 출력
		System.out.println(inversionX + inversionY);
	}
}