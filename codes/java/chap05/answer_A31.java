import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long N = sc.nextLong();
		long A1 = N /  3; // 3으로 나누어떨어지는 수의 개수
		long A2 = N /  5; // 5로 나누어떨어지는 수의 개수
		long A3 = N / 15; // 3, 5 모두로 나누어떨어지는 수(= 15의 배수)의 개수
		System.out.println(A1 + A2 - A3);
	}
};
