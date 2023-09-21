import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해 Scanner 대신 BufferedReader를 사용)
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
		
		// 인접 리스트 생성
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// State 타입끼리 비교하는 함수너비 우선 탐색 초기화(dist[i]=? 가 아닌 dist[i]=-1로 초기화됨을 주의)
		int[] dist = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = -1;
		}
		dist[1] = 0;
		Queue<Integer> Q = new LinkedList<>(); // 큐 Q 정의하기
		Q.add(1);

		// 너비 우선 탐색
		while (Q.size() >= 1) {
			int pos = Q.remove(); // 큐 Q의 첫 번째 요소를 제거하고 그 값을 pos에 대입
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex);
				}
			}
		}
		
		// 정점 1에서 각 정점까지의 최단 거리를 출력(빠른 출력을 위해 System.out.println이 아닌 PrintWriter를 사용)
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			output.println(dist[i]);
		}
		output.flush();
	}
}