// 본 프로그램은 책 XXX쪽 '더 높은 순위를 위하여'를 구현한 담금질 기법 코드입니다.
// 기반이 되는 등산 알고리즘의 구현은 answer_A50_extra.java를 참고하시기 바랍니다.
// ※ 예상 점수는 약 99.948억 점입니다.

import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		final int N = 100;
		final int Q = 1000;
		int[][] A = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = sc.nextInt();
			}
		}

		// 초기 해법 생성
		Random rnd = new Random();
		Answer ans = new Answer(N, Q, A, rnd);

		// 등산 알고리즘：변수 설정 (5.4 초 반복 설정)
		final double TIME_LIMIT = 5.4;
		long ti = System.currentTimeMillis();
		int currentScore = ans.getScore();

		// 등산 알고리즘 시작
		int loops = 0;
		while ((System.currentTimeMillis() - ti) / 1000.0 < TIME_LIMIT) {
			// '작은 변화'를 무작위로 선택
			int t = rnd.nextInt(Q);
			int old_x = ans.X[t], new_x = ans.X[t] + (rnd.nextInt(19) - 9);  // X[t]를 -9에서 +9까지 증가 또는 감소
			int old_y = ans.Y[t], new_y = ans.Y[t] + (rnd.nextInt(19) - 9);  // Y[t]를 -9에서 +9까지 증가 또는 감소
			int old_z = ans.H[t], new_z = ans.H[t] + (rnd.nextInt(39) - 19); // H[t]를 -19에서 +19까지 증가 또는 감소
			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N || new_z <= 0 || new_z > N) {
				continue;
			}
			// 일단 변경하고, 점수를 평가한다
			ans.change(t, new_x, new_y, new_z);
			int newScore = ans.getScore();
			// 점수에 따라 채용 여부를 결정한다
			if (currentScore < newScore) {
				currentScore = newScore;
			}
			else {
				ans.change(t, old_x, old_y, old_z);
			}
			loops += 1;
		}

		// 출력
		System.out.println(Q);
		for (int i = 0; i < Q; i++) {
			System.out.println(ans.X[i] + " " + ans.Y[i] + " " + ans.H[i]);
		}
		System.err.println("loops = " + loops);
		System.err.println("score = " + currentScore);
	}

	// 조작 절차 및 판넬을 기록하는 구조물 Answer
	// (여기서는 책에 있는 코드와 달리, 작업의 번호는 1-indexed가 아닌 0-indexed로 구현했습니다(즉, 0에서 999까지 숫자가 나옵니다)).
	static class Answer {
		int N; // 보드 크기
		int Q; // 조작 횟수
		int[] X;
		int[] Y;
		int[] H;
		int[][] A;
		int[][] B;
		// 초기 해법 생성
		public Answer(int N, int Q, int[][] A, Random rnd) {
			this.N = N;
			this.Q = Q;
			this.A = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					this.A[i][j] = A[i][j];
				}
			}
			X = new int[Q];
			Y = new int[Q];
			H = new int[Q];
			B = new int[N][N];
			for (int i = 0; i < Q; i++) {
				X[i] = rnd.nextInt(N); // 0 이상 N-1 이하의 무작위 정수
				Y[i] = rnd.nextInt(N); // 0 이상 N-1 이하의 무작위 정수
				H[i] = 1;
				B[Y[i]][X[i]] += 1;
			}
		}
		// X[t] = x, Y[t] = y, H[t] = h로 변경하는 함수
		void change(int t, int x, int y, int h) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					B[i][j] -= Math.max(H[t] - Math.abs(Y[t] - i) - Math.abs(X[t] - j), 0);
				}
			}
			X[t] = x;
			Y[t] = y;
			H[t] = h;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					B[i][j] += Math.max(H[t] - Math.abs(Y[t] - i) - Math.abs(X[t] - j), 0);
				}
			}
		}
		// 현재 점수를 반환하는 함수
		int getScore() {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					sum += Math.abs(A[i][j] - B[i][j]);
				}
			}
			return 200000000 - sum;
		}
	}
}