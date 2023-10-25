import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 세로 길이를 1부터 √N까지 전체 탐색
		long answer = (1L << 60);
		for (long x = 1; x * x <= N; x++) {
			if (N % x == 0) {
				answer = Math.min(answer, 2 * x + 2 * (N / x));
			}
		}
		
		// 답 출력
		System.out.println(answer);
	}
}