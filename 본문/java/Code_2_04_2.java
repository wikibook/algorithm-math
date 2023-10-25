import java.util.*;

class Code_2_04_2 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		// 답 구하기
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			// mod 계산은 2.2절 참고
			if (i % X == 0 || i % Y == 0) {
				cnt++;
			}
		}
		
		// 출력
		System.out.println(cnt);
	}
}
