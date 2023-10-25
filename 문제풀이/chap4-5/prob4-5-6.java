import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt(), W = sc.nextInt();
		int sx = sc.nextInt(), sy = sc.nextInt();
		int gx = sc.nextInt(), gy = sc.nextInt();
		String[] c = new String[H + 1];
		for (int i = 1; i <= H; i++) {
			c[i] = sc.next();
		}
		int start = (sx - 1) * W + sy;
		int goal = (gx - 1) * W + gy;
		
		// 인접리스트 작성
		ArrayList<Integer>[] G = new ArrayList[H * W + 1];
		for (int i = 1; i <= H * W; i++) {
			G[i] = new ArrayList<Integer>();
		}
		
		// 가로 방향 엣지 [(i, j) - (i, j+1)]를 그래프에 추가
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W - 1; j++) {
				if (c[i].charAt(j - 1) == '.' && c[i].charAt(j) == '.') {
					int idx1 = (i - 1) * W + j; // (i, j)의 정점 번호
					int idx2 = (i - 1) * W + (j + 1); // (i, j + 1)의 정점 번호
					G[idx1].add(idx2);
					G[idx2].add(idx1);
				}
			}
		}
		
		// 세로 방향 엣지 [(i, j) - (i+1, j)]를 그래프에 추가
		for (int i = 1; i <= H - 1; i++) {
			for (int j = 1; j <= W; j++) {
				if (c[i].charAt(j - 1) == '.' && c[i + 1].charAt(j - 1) == '.') {
					int idx1 = (i - 1) * W + j; // (i, j)의 정점 번호
					int idx2 = i * W + j; // (i + 1, j)의 정점 번호
					G[idx1].add(idx2);
					G[idx2].add(idx1);
				}
			}
		}
		
		// 너비 우선 탐색 초기화(dist[i] = -1일 때 아직 도달하지 않은 흰색 정점으로 취급)
		int[] dist = new int[H * W + 1];
		for (int i = 1; i <= H * W; i++) {
			dist[i] = -1;
		}
		Queue<Integer> Q = new LinkedList<>(); // 큐 Q 정의
		dist[start] = 0;
		Q.add(start); // Q에 start를 추가

		// 너비 우선 탐색
		while (Q.size() >= 1) {
			int pos = Q.remove(); // Q의 가장 앞을 확인하고, 이를 추출합니다.
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex); // Q에 nex를 추가
				}
			}
		}
		
		// 답 출력
		System.out.println(dist[goal]);
	}
}
