import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Point2D[] points = new Point2D[N + 1];
		for (int i = 1; i <= N; i++) {
			points[i] = new Point2D(sc.nextInt(), sc.nextInt());
		}

		// 탐욕 알고리즘
		int[] answer = playGreedy(N, points);

		// 답을 출력
		for (int i = 1; i <= N + 1; i++) {
			System.out.println(answer[i]);
		}
	}

	// 탐욕 알고리즘을 사용해 답을 구하는 함수
	static int[] playGreedy(int N, Point2D[] points) {
		// 배열 초기화
		int currentPlace = 1;
		int[] P = new int[N + 2];
		boolean[] visited = new boolean[N + 1]; // Java에서 new로 초기화한 배열의 요소는 false가 된다는 점에 유의하세요.
		P[1] = 1;
		visited[1] = true;

		// 탐욕 알고리즘 시작
		for (int i = 2; i <= N; i++) {
			double minDist = 1.0e+99; // 현 시점에서의 거리의 최소
			int minID = -1;           // 다음에는 어떤 도시로 이동해야 할까?
			// 거리가 최소가 되는 도시를 찾는다
			for (int j = 1; j <= N; j++) {
				if (visited[j]) {
					continue;
				}
				double newDist = points[currentPlace].dist(points[j]);
				if (minDist > newDist) {
					minDist = newDist;
					minID = j;
				}
			}

			// 현재 위치 업데이트
			visited[minID] = true;
			P[i] = minID;
			currentPlace = minID;
		}

		// 최후에 방문하는 도시
		P[N + 1] = 1;

		return P;
	}

	// 2차원의 점을 다루는 클래스 Point2D
	static class Point2D {
		int x, y;
		public Point2D(int x, int y) {
			this.x = x;
			this.y = y;
		}
		// 두 점 사이의 거리를 구하는 함수
		double dist(Point2D p) {
			return Math.sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
		}
	}
}