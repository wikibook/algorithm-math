import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int K = sc.nextInt();

		// 완전 탐색
		int Answer = 0;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				int z = K - x - y; // 흰 카드에 적혀야 하는 정수
				if (z >= 1 && z <= N) Answer += 1;
			}
		}

		// 출력
		System.out.println(Answer);
	}
};
