import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입력을 위해 Scanner 대신 BufferedReader를 사용)
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
			G[i] = new ArrayList<Integer>(); // G[i]는 버텍스 i에 인접한 버텍스의 목록
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]); // 버텍스 A[i]에 인접한 버텍스로 B[i]를 추가
			G[B[i]].add(A[i]); // 버텍스 B[i]에 인접한 버텍스로 A[i]를 추가
		}
		
		// 출력(G[i].size() 는 정점 i에 인접한 정점 목록의 크기 = 차수)
		//(빠른 출력을 위해 System.out.println이 아닌 PrintWriter를 사용)
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			output.print(i + ": {");
			for (int j = 0; j < G[i].size(); j++) {
				if (j >= 1) {
					output.print(", ");
				}
				output.print(G[i].get(j)); // G[i].get(j)는 정점 i에 인접한 정점 중 j+1번째 정점
			}
			output.println("}");
		}
		output.flush();
	}
}