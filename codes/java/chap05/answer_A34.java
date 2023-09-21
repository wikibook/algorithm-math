import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// Grundy 수치를 구함
		// 변수 grundy[i]: 돌이 i개일 때의 Grundy 수
		// 변수 Transit[i]: Grundy 수가 i가 되도록 전이할 수 있는가
		int[] grundy = new int[100001];
		for (int i = 0; i <= 100000; i++) {
			boolean[] Transit = {false, false, false};
			if (i >= X) Transit[grundy[i-X]] = true;
			if (i >= Y) Transit[grundy[i-Y]] = true;
			if (Transit[0] == false) grundy[i] = 0;
			else if (Transit[1] == false) grundy[i] = 1;
			else grundy[i] = 2;
	  }
		
		// 출력
		int XOR_Sum = 0;
		for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ grundy[A[i]]);
		if (XOR_Sum != 0) System.out.println("First");
		if (XOR_Sum == 0) System.out.println("Second");
	}
};
