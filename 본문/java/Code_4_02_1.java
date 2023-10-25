import java.util.*;
import java.io.*;

class Code_4_02_1 {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해서, Scanner 대신에 BufferedReader를 사용했습니다)
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		int[] A = new int[N + 1];
		int[] L = new int[Q + 1];
		int[] R = new int[Q + 1];
		st = new StringTokenizer(buff.readLine());
		for (int i = 1; i <= N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		for (int j = 1; j <= Q; j++) {
			st = new StringTokenizer(buff.readLine());
			L[j] = Integer.parseInt(st.nextToken());
			R[j] = Integer.parseInt(st.nextToken());
		}
		
		// 누적합 구하기
		int[] B = new int[N + 1];
		B[0] = 0;
		for (int i = 1; i <= N; i++) {
			B[i] = B[i - 1] + A[i];
		}
		
		// 답을 계산하고 출력
		for (int j = 1; j <= Q; j++) {
			System.out.println(B[R[j]] - B[L[j] - 1]);
		}
	}
}
