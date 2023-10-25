import java.util.*;

class Code_4_05_1 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		// 인접리스트 작성
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>(); // G[i]는 정점i와 인접한 정점 리스트
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]); // 정점 A[i]와 인접한 정점으로 B[i]를 추가
			G[B[i]].add(A[i]); // 정점 B[i]와 인접한 정점으로 A[i]를 추가
		}
		
		// 출력(G[i].size()는 정점 i에 인접한 정점 리스트의 크기이므로 "차수"입니다).
		for (int i = 1; i <= N; i++) {
			System.out.format("%d: {", i);
			for (int j = 0; j < G[i].size(); j++) {
				if (j >= 1) {
					System.out.print(",");
				}
				System.out.print(G[i].get(j)); // G[i].get(j)는 정점i와 인접한 정점 중에서 j번째 정점
			}
			System.out.println("}");
		}
	}
}
