import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long L = sc.nextLong();
		long R = sc.nextLong();
		int D = (int)(R - L);
		
		// 배열 초기화
		boolean[] isprime = new boolean[D + 1];
		for (int i = 0; i <= D; i++) {
			isprime[i] = true;
		}

		// L = 1  때의 조건 분기(코너 케이스)
		if (L == 1) {
			isprime[0] = false;
		}
		
		// 에라토스테네스의 체
		for (int i = 2; (long)i * i <= R; i++) {
			int start = (int)(((L + i - 1) / i * i) - L); // (L 이상에서 최소인 i의 배수) - L
			// L 이상 R 이하에서 i를 제외한 i의 배수에 X 표시
			for (int j = start; j <= D; j += i) {
				if (j + L == (long)i) continue;
				isprime[j] = false;
			}
		}
		
		// 갯수 세서 출력하기
		int answer = 0;
		for (int i = 0; i <= D; i++) {
			if (isprime[i] == true) {
				answer += 1;
			}
		}
		System.out.println(answer);
	}
}