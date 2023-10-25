import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] B = new int[N];
		for (int i = 1; i <= N - 1; i++) {
			B[i] = sc.nextInt();
		}
	
		// 수열A의 요소 합계 구하기
		int answer = B[1] + B[N - 1];
		for (int i = 2; i <= N - 1; i++) {
			answer += Math.min(B[i - 1], B[i]);
		}
		
		// 답 출력
		System.out.println(answer);
	}
}