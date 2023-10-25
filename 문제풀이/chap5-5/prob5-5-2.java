import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double[] A = new double[N + 1];
		double[] B = new double[N + 1];
		double[] C = new double[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextDouble();
			B[i] = sc.nextDouble();
			C[i] = sc.nextDouble();
		}
		
		// 교점 전체 탐색
		double Answer = 0.0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				// 교점을 갖지 않는 경우
				if (A[i] * B[j] == A[j] * B[i]) continue;
				
				// i번째 직선(조건식의 경계)와 j번째 직선(조건식의 경계) 사이의 교점을 구함
				double px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
				double py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
				
				// 좌표 (px, py)가 N개의 조건을 만족하는지 확인
				// C++ 코드에서 check 함수에 해당
				boolean ret = true;
				for (int k = 1; k <= N; k++) {
					if (A[k] * px + B[k] * py > C[k]) ret = false;
				}
				if (ret == true) {
					Answer = Math.max(Answer, px + py);
				}
			}
		}
		
		// 출력
		System.out.format("%.12f\n", Answer);
	}
}