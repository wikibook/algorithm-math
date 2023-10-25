import java.util.*;

class Code_5_09_2 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		
		// 영화 선택 시뮬레이션
		// 볼 수 있는 영화 중 종료 시간 최솟값 minEndtime은 일단 1000000(INF로 설정)처럼 나올 수 없는 값으로 설정합니다.
		final int INF = 1000000;
		int currentTime = 0; // currentTime는 현재 시각(직전에 보았던 영화의 종료 시각)
		int answer = 0;
		while (true) {
			int minEndtime = INF;
			for (int i = 1; i <= N; i++) {
				if (L[i] >= currentTime) {
					minEndtime = Math.min(minEndtime, R[i]);
				}
			}
			if (minEndtime == INF) {
				break;
			}
			currentTime = minEndtime;
			answer += 1;
		}
		
		// 답 출력
		System.out.println(answer);
	}
}
