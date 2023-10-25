import java.util.*;

class Code_5_02_1 {
	public static void main(String[] args) {
		// 주의: 다음 프로그램은 N >= 1에서 정상적으로 동작합니다.N=0일 때는 답이 "1"이므로, 조건 분기를 따로 나누어서 출력하면 됩니다.
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		if (N % 4 == 1) {
			System.out.println(2);
		}
		if (N % 4 == 2) {
			System.out.println(4);
		}
		if (N % 4 == 3) {
			System.out.println(8);
		}
		if (N % 4 == 0) {
			System.out.println(6);
		}
	}
}
