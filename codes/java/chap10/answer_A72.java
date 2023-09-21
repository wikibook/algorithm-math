import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력(책과 달리 c[i][j]는 0-indexed로 입력합니다.)
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		char[][] c = new char[H][W];
		for (int i = 0; i < H; i++) {
			String cs = sc.next();
			for (int j = 0; j < W; j++) {
				c[i][j] = cs.charAt(j);
			}
		}

		// 비트 완전 탐색
		int answer = 0;
		for (int t = 0; t < (1 << H); t++) {
			// 우선은 칸을 초기매트릭스에 설정
			char[][] d = new char[H][W];
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					d[i][j] = c[i][j];
				}
			}

			// 행에 대해 조작을 수행한다
			// 변수 remainingSteps는 남은 조작 횟수
			int remainingSteps = K;
			for (int i = 0; i < H; i++) {
				int wari = (1 << i);
				if ((t / wari) % 2 == 1) {
					remainingSteps -= 1;
					for (int j = 0; j < W; j++) {
						d[i][j] = '#';
					}
				}
			}

			// 열에 대한 조작을 수행한다
			if (remainingSteps >= 0) {
				int subAnswer = paintRow(H, W, d, remainingSteps);
				answer = Math.max(answer, subAnswer);
			}
		}

		// 출력
		System.out.println(answer);
	}

	// 남은 remainingSteps 횟수의 '열에 대한 조작'으로 최대 몇 개의 칸을 검정색으로 만들 수 있는지를 반환하는 함수
	static int paintRow(int H, int W, char[][] d, int remainingSteps) {
		// 각 열에 대한 '흰색 칸의 개수'를 계산하고 내림차순으로 정렬한다
		PairInt[] column = new PairInt[W];
		for (int j = 0; j < W; j++) {
			int cnt = 0;
			for (int i = 0; i < H; i++) {
				if (d[i][j] == '.') {
					cnt += 1;
				}
			}
			column[j] = new PairInt(cnt, j);
		}
		Arrays.sort(column, Collections.reverseOrder());

		// 열에 대한 조작을 수행한다
		for (int j = 0; j < remainingSteps; j++) {
			int idx = column[j].second;
			for (int i = 0; i < H; i++) {
				d[i][idx] = '#';
			}
		}

		// 검은색 칸의 개수를 센다
		int ret = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (d[i][j] == '#') {
					ret += 1;
				}
			}
		}
		return ret;
	}

	// int 타입 쌍의 클래스 PairInt
	static class PairInt implements Comparable<PairInt> {
		int first, second;
		public PairInt(int first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override public int compareTo(PairInt p) {
			// PairInt 타입끼리 비교하는 함수
			if (this.first < p.first || (this.first == p.first && this.second < p.second)) {
				return -1;
			}
			if (this.first > p.first || (this.first == p.first && this.second > p.second)) {
				return 1;
			}
			return 0;
		}
	}
}