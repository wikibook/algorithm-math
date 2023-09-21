import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해 Scanner 대신 BufferedReader를 사용)
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int[] A = new int[N + 1];
		st = new StringTokenizer(buff.readLine());
		for (int i = 2; i <= N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		
		// 인접 리스트 생성
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 2; i <= N; i++) {
			G[A[i]].add(i); // '상사→부하' 방향으로 에지를 추가
		}

		// 동적 계획 알고리즘(dp[x]는 직원 x의 부하직원 수)
		int[] dp = new int[N + 1]; // Java에서 new로 초기화한 배열의 요소는 0이 된다는 점에 유의하세요.
		for (int i = N; i >= 1; i--) {
			for (int j = 0; j < G[i].size(); j++) {
				dp[i] += (dp[G[i].get(j)] + 1);
			}
		}
		
		// 답을 공백으로 구분해서 출력(빠른 출력을 위해 System.out.println이 아닌 PrintWriter를 사용)
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			if (i >= 2) {
				output.print(" ");
			}
			output.print(dp[i]);
		}
		output.println();
		output.flush();
	}
}