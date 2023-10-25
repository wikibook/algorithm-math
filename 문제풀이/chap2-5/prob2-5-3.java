import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		long N = sc.nextInt();

		// 답 계산
		long Answer = 1;
		for (int i = 1; i <= N; i++) Answer *= i;

		// 출력
		System.out.println(Answer);
	}
};