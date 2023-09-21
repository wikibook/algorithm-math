import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int X = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 완전 탐색(변수 Answer는 '기존에 x를 발견했는가'를 나타냄)
		boolean Answer = false;
		for (int i = 1; i <= N; i++) {
			if (A[i] == X) Answer = true;
		}

		// 출력
		if (Answer == true) System.out.println("Yes");
		else System.out.println("No");
	}
};
