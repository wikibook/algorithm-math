import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int Q = sc.nextInt();

		// 배열 초기화
		int State = 1;
		int[] E = new int[N + 1];
		for (int i = 1; i <= N; i++) E[i] = i;

		// 쿼리 처리
		for (int i = 1; i <= Q; i++) {
			int Type, x, y;
			Type = sc.nextInt();

			// [1] 변경 조작
			if (Type == 1) {
				x = sc.nextInt();
				y = sc.nextInt();
				if (State == 1) E[x] = y;
				if (State == 2) E[N+1-x] = y;
			}

			// [2] 반전 조작
			if (Type == 2) {
				if (State == 1) State = 2;
				else State = 1;
			}

			// [3] 취득 조작
			if (Type == 3) {
				x = sc.nextInt();
				if (State == 1) System.out.println(E[x]);
				if (State == 2) System.out.println(E[N + 1 - x]);
			}
		}
	}
};
