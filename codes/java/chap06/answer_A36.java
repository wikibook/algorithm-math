import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int K = sc.nextInt();

		// 출력
		if (K >= 2*N-2 && K%2 == 0) System.out.println("Yes");
		else System.out.println("No");
	}
};
