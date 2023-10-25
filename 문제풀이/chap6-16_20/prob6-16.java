import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		
		// 모든 (a, b, c) 조합 확인하기
		int answer = 0;
		for (int a = 1; a <= N; a++) {
			for (int b = a + 1; b <= N; b++) {
				for (int c = b + 1; c <= N; c++) {
					if (a + b + c == X) {
						answer += 1;
					}
				}
			}
		}
		
		// 답 출력
		System.out.println(answer);
	}
}