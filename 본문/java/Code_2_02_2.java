import java.util.*;

class Code_2_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(); // a 입력
		int b = sc.nextInt(); // b 입력
		System.out.println(a & b); // a AND b의 값을 출력
		System.out.println(a | b); // a OR b의 값을 출력
		System.out.println(a ^ b); // a XOR b의 값을 출력
	}
};
