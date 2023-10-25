import java.util.*;
import java.io.*;

class Code_4_05_3 {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해서, Scanner 대신에 BufferedReader를 사용했습니다)
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
		}
		
		// 인접리스트 작성
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 너비 우선 탐색 초기화(dist[i] = -1일 때 아직 도달하지 않은 흰색 정점으로 취급)
		int[] dist = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = -1;
		}
		Queue<Integer> Q = new LinkedList<>(); // 큐 Q 정의
		dist[1] = 0;
		Q.add(1); // Q에 1을 추가(조작1)

		// 너비 우선 탐색
		while (Q.size() >= 1) {
			int pos = Q.remove(); // Q의 앞을 확인하고, 이를 꺼냄(조작2, 3)
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex); // Q에 nex를 추가(조작1)
				}
			}
		}
		
		// 정점1에서 각 정점까지의 최단 거리를 출력
		for (int i = 1; i <= N; i++) {
			System.out.println(dist[i]);
		}
	}
}
