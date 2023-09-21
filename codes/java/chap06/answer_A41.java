import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		String S = sc.next();

		// 답을 구한다
		boolean Answer = false;
		for (int i = 0; i <= N - 3; i++) {
			if (S.charAt(i)=='R' && S.charAt(i+1)=='R' && S.charAt(i+2)=='R') Answer = true;
			if (S.charAt(i)=='B' && S.charAt(i+1)=='B' && S.charAt(i+2)=='B') Answer = true;
		}

		// 출력
		if (Answer == true) System.out.println("Yes");
		else System.out.println("No");
	}
};
