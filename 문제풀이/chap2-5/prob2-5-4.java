import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		int N = sc.nextInt();
		
		// 출력
		for (int i = 2; i <= N; i++) {
			if (isPrime(i) == true) {
				if (i >= 3) System.out.print(" ");
				System.out.print(i);
			}
		}
		System.out.println();
	}
	static boolean isPrime(long N) {
		// 2 이상의 정수 N을 매개변수로 받고, N이 소수라면 True를, 아니라면 False를 리턴하는 함수
		for (long i = 2; i <= N - 1; i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}
}