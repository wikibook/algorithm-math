import java.util.*;

class Code_4_04_1 {
	public static void main(String[] args) {
		// 입력 → 배열 prime 초기화
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		boolean[] prime = new boolean[N + 1];
		for (int i = 2; i <= N; i++) {
			prime[i] = true;
		}
		
		// 에라토스테네스의 체
		for (int i = 2; i * i <= N; i++) {
			if (prime[i] == true) {
				for (int x = 2 * i; x <= N; x += i) {
					prime[x] = false;
				}
			}
		}
		
		// N 이하의 소수를 오름차순으로 출력
		for (int i = 2; i <= N; i++) {
			if (prime[i] == true) {
				System.out.println(i);
			}
		}
	}
}
