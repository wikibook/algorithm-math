import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력
		int A = sc.nextInt();
		int B = sc.nextInt();

		// 출력
		System.out.println(GCD(A, B));
	}

	// 양의 정수 A와 B의 최대공약수를 반환하는 함수
	// GCD는 Greatest Common Divisor(최대공약수)를 의미
	static int GCD(int A, int B) {
		while (A >= 1 && B >= 1) {
			if (A >= B) {
				A %= B; // A의 값을 변경하는 경우
			}
			else {
				B %= A; // B의 값을 변경하는 경우
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
};
