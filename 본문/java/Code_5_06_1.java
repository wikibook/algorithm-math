import java.util.*;

class Code_5_06_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int answer = 0;
		for (int i = 1; i <= B; i++) {
			if (shouMondai(A, B, i) == true) {
				answer = i;
			}
		}
		System.out.println(answer);
	}
	static boolean shouMondai(int A, int B, int t) {
		// 작은 문제 t를 푸는 함수
		int cl = (A + t - 1) / t; // A÷t의 소수점 아래를 자릅니다.
		int cr = B / t; // B÷t의 소수점 아래를 자릅니다.
		return (cr - cl >= 1); // cr - cl >= 1이라면 true, 그렇지 않은 경우 false를 리턴
	}
}
