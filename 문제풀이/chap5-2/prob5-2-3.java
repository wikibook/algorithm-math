import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 배열 초기화
		long[] First = new long[N + 1];
		long[] Second = new long[N + 1];
		for (int i = 1; i <= N; i++) First[i] = -1;
		for (int i = 1; i <= N; i++) Second[i] = -1;
		
		// 답 구하기(cur은 현재 있는 마을의 번호)
		long cnt = 0;
		int cur = 1;
		while (true) {
			// First, Second 변경
			if (First[cur] == -1) First[cur] = cnt;
			else if (Second[cur] == -1) Second[cur] = cnt;
			
			// K회 이동 후에 마을 cur에 있는지 판정
			if (cnt == K) {
				System.out.println(cur);
				System.exit(0);
			}
			else if (Second[cur] != -1L && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
				System.out.println(cur);
				System.exit(0);
			}
			
			// 이동
			cur = A[cur];
			cnt += 1;
		}
	}
}