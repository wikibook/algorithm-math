import java.util.*;

class Main {
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
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 답 구하기
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			for (int j = 0; j < G[i].size(); j++) {
				// G[i][j]는 정점 i에 인접한 정점 중 j번째 정점
				if (G[i].get(j) < i) {
					cnt += 1;
				}
			}
			// 자기자신보다 번호가 작은 인접한 정점이 1개 있다면, answer에 1을 추가
			if (cnt == 1) {
				answer += 1;
			}
		}
		
		// 답 출력
		System.out.println(answer);
	}
}
