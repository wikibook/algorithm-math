import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력 → 배열 초기화
		int N = sc.nextInt();
		long[] F = new long[N + 1];
		for (int i = 1; i <= N; i++) F[i] = 0;
		
		// F[1], F[2], ..., F[N]를 계산하기
		for (int i = 1; i <= N; i++) {
			// F[i], F[2i], F[3i], ...에 1을 추가하기
			for (int j = i; j <= N; j += i) F[j] += 1;
		}
		
		// 답 구하기
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += F[i] * i;
		}
		System.out.println(Answer);
	}
}