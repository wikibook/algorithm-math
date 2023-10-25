import java.util.*;

class Code_3_06_6 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int answer = func(N);
		System.out.println(answer);
	}
	static int func(int N) {
		// func(N) → func(N-1) → ... → func(0) → func(-1) → func(-2) → ...처럼 무한하게 호출되어서, 프로그램이 정상적으로 작동하지 않습니다.
		return func(N - 1) * N;
	}
}
