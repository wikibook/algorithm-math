import java.util.*;

class Code_3_06_3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		System.out.println(func(N));
	}
	static int func(int N) {
		if (N == 1) {
			return 1; // 이처럼 재귀 함수를 끝내는 경우를 "베이스 케이스"라고 부릅니다.
		}
		return func(N - 1) * N;
	}
}
