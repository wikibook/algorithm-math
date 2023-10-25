import java.util.*;

class Code_5_10_3 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long X = sc.nextLong();
		long Y = sc.nextLong();
		
		// 4개의 정수 (a, b, c, d)를 전체 탐색
		boolean flag = false;
		for (int a = 1; a <= N; a++) {
			for (int b = a; b <= N; b++) {
				for (int c = b; c <= N; c++) {
					for (int d = c; d <= N; d++) {
						if (a + b + c + d == X && (long)a * b * c * d == Y) {
							flag = true; // 답을 찾았다면 flag를 true로 변경합니다.
						}
					}
				}
			}
		}
		
		// 답 출력
		if (flag == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
