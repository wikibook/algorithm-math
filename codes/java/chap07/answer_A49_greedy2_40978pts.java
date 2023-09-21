// ###############################################
// # 책 XXX페이지 후반부의 평가 함수를 이용한 구현입니다.
// ###############################################

import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = 20;
		int T = sc.nextInt();
		int[] P = new int[T + 1];
		int[] Q = new int[T + 1];
		int[] R = new int[T + 1];
		for (int i = 1; i <= T; i++) {
			P[i] = sc.nextInt();
			Q[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}

		// 배열 A 초기화
		int[] A = new int[21];
		int[] PatA = new int[21];
		int[] PatB = new int[21];
		for (int i = 1; i <= 20; i++) A[i] = 0;

		// 탐욕 알고리즘
		for (int i = 1; i <= T; i++) {
			// 패턴 A일 때의 점수 구하기
			int ScoreA = 0;
			for (int j = 1; j <= 20; j++) PatA[j] = A[j];
			PatA[P[i]] += 1;
			PatA[Q[i]] += 1;
			PatA[R[i]] += 1;
			for (int j = 1; j <= 20; j++) ScoreA += Math.abs(PatA[j]);

			// 패턴 B일 때의 점수 구하기
			int ScoreB = 0;
			for (int j = 1; j <= 20; j++) PatB[j] = A[j];
			PatB[P[i]] -= 1;
			PatB[Q[i]] -= 1;
			PatB[R[i]] -= 1;
			for (int j = 1; j <= 20; j++) ScoreB += Math.abs(PatB[j]);

			// 점수가 낮은 쪽을 채택
			if (ScoreA <= ScoreB) {
				System.out.println("A");
				for (int j = 1; j <= 20; j++) A[j] = PatA[j];
			}
			else {
				System.out.println("B");
				for (int j = 1; j <= 20; j++) A[j] = PatB[j];
			}
		}
	}
};
