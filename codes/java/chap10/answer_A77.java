import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}

		// 바이너리 서치(left: 현재 하한선 / right: 현재 상한선)
		int left = 1, right = 1000000000;
		while (left < right) {
			int mid = (left + right + 1) / 2;
			boolean answer = check(N, L, K, A, mid);
			if (answer == false) {
				right = mid - 1; // 답이 전반 부분으로 좁혀진다
			}
			else {
				left = mid;      // 답이 후반 부분으로 좁혀진다
			}
		}

		// 출력
		System.out.println(left);
	}

	// 점수의 최대값이 x 이상인지 여부를 판단하는 함수
	static boolean check(int N, int L, int K, int[] A, int x) {
		int count = 0;      // 현재 몇 번을 끊었는지를 나타낸다
		int lastKireme = 0; // 마지막에 자른 곳을 표시한다
		for (int i = 1; i <= N; i++) {
			if (A[i] - lastKireme >= x && L - A[i] >= x) {
				count += 1;
				lastKireme = A[i];
			}
		}
		return (count >= K);
	}
}