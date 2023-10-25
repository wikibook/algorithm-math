import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		// 답 계산
		double Answer = 0.0;
		for (int i = N; i >= 1; i--) {
			Answer += 1.0 * N / i;
		}
		
		// 출력
		System.out.format("%.12f\n", Answer);
	}
}