import java.util.*;

class Code_5_05_2 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] X = new int[N + 1];
		int[] Y = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
		}
		
		// 왼쪽 끝 x, 오른쪽 끝 x, 아래쪽 끝 y, 위쪽 끝 y를 전체 탐색(각각 번호가 i, j, k, l)
		long answer = (1L << 62); // 일단 나올 수 없는 값을 설정
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					for (int l = 1; l <= N; l++) {
						int cl = X[i]; // 왼쪽 끝의 x 좌표
						int cr = X[j]; // 오른쪽 끝의 x 좌표
						int dl = Y[k]; // 아래쪽 끝의 y 좌표
						int dr = Y[l]; // 위쪽 끝의 y 좌표
						if (check_numpoints(N, X, Y, cl, cr, dl, dr) >= K) {
							long area = (long)(cr - cl) * (dr - dl);
							answer = Math.min(answer, area);
						}
					}
				}
			}
		}
		
		// 답 출력
		System.out.println(answer);
	}
	static int check_numpoints(int N, int[] X, int[] Y, int lx, int rx, int ly, int ry) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			// 점(X[i], Y[i])가 직사각형에 포함되어 있는지 판정
			if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) {
				cnt += 1;
			}
		}
		return cnt;
	}
}
