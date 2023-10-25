import java.util.*;

class Code_5_04_1 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		// 사건B의 개수를 yeosagun(여사건) 변수로 셉니다.
		long yeosagun = 0;
		for (int a = 1; a <= N; a++) {
			int l = Math.max(1, a - (K - 1)); // b, c의 탐색 범위 하한 l
			int r = Math.min(N, a + (K - 1)); // b, c의 탐색 범위 상한 r
			for (int b = l; b <= r; b++) {
				for (int c = l; c <= r; c++) {
					if (Math.abs(b - c) <= K - 1) {
						yeosagun += 1;
					}
				}
			}
		}
		// 답 출력
		long answer = (long)N * N * N - yeosagun;
		System.out.println(answer);
	}
}
