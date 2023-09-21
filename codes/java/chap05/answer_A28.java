import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		char[] T = new char[N + 1];
		long[] A = new long[N + 1];
		for (int i = 1; i <= N; i++) {
			T[i] = sc.next().charAt(0);
			A[i] = sc.nextInt();
		}

		// 출력(Answer는 현재 칠판의 수)
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			if (T[i] == '+') Answer += A[i];
			if (T[i] == '-') Answer -= A[i];
			if (T[i] == '*') Answer *= A[i];

			// 뺄셈의 답이 0 미만이 된 경우
			if (Answer < 0) Answer += 10000;

			// 여기에서 나머지를 구한다!
			Answer %= 10000;
			System.out.println(Answer);
		}
	}
};
