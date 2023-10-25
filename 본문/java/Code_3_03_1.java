import java.util.*;

class Code_3_03_1 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 5개의 카드 번호(i, j, k, l, m)를 전체 탐색
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				for (int k = j + 1; k <= N; k++) {
					for (int l = k + 1; l <= N; l++) {
						for (int m = l + 1; m <= N; m++) {
							if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) {
								answer++;
							}
						}
					}
				}
			}
		}
		
		// 출력
		System.out.println(answer);
	}
}
