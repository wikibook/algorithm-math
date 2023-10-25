import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 출력
		System.out.println(N * (N - 1) / 2);
	}
}