import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] X = new long[N];
		long[] Y = new long[N];
		for (int i = 0; i < N; i++) {
			X[i] = sc.nextLong();
			Y[i] = sc.nextLong();
		}
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		// 교차 횟수 세기
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			long xa = X[i] - A, ya = Y[i] - B;
			long xb = X[(i + 1) % N] - A, yb = Y[(i + 1) % N] - B;
			if (ya > yb) {
				long tmp1 = xa; xa = xb; xb = tmp1;
				long tmp2 = ya; ya = yb; yb = tmp2;
			}
			if (ya <= 0 && 0 < yb && xa * yb - xb * ya < 0) {
				cnt += 1;
			}
		}
		
		// 답 출력
		if (cnt % 2 == 1) {
			System.out.println("INSIDE");
		}
		else {
			System.out.println("OUTSIDE");
		}
	}
}