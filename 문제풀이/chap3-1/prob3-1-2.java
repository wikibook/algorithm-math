import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		long N = sc.nextLong();
		
		// 소인수분해/출력
		boolean flag = false;
		for (long i = 2; i * i <= N; i++) {
			while (N % i == 0) {
				if (flag == true) System.out.print(" ");
				flag = true;
				N /= i;
				System.out.print(i);
			}
		}
		
		// 마지막에 남은 N
		if (N >= 2) {
			if (flag == true) System.out.print(" ");
			flag = true;
			System.out.print(N);
		}
		System.out.println();
	}
}