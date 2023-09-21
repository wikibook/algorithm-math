import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();

		// 윗자리부터 순서대로 '2진법으로 변환한 값'을 구한다
		for (int x = 9; x >= 0; x--) {
			int wari = (1 << x); // 2의 x제곱
			System.out.print((N / wari) % 2); // 분할 결과에 따라 0 또는 1 출력
		}
		System.out.println(); // 마지막에 줄바꿈한다
	}
};
