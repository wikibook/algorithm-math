import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// N = 2^k-1 형태로 나타낼 수 있는지 확인하기
		boolean flag = false;
		for (int i = 1; i <= 60; i++) {
			if (N == (1L << i) - 1) {
				flag = true;
			}
		}
		
		// 출력
		if (flag == true) System.out.println("Second");
		else System.out.println("First");
	}
}