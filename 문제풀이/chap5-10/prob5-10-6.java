import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long B = sc.nextLong();
		
		// 각 자릿수의 곱 후보를 모두 나열
		func(0, 0);
		
		// m - f(m) == B이 되는지 확인
		long Answer = 0;
		for (long fm : fm_cand) {
			long m = fm + B;
			long prod_m = product(m);
			if (m - prod_m == B && m <= N) {
				Answer += 1;
			}
		}
		
		// 출력
		System.out.println(Answer);
	}
	
	static Set<Long> fm_cand = new TreeSet<Long>();
	
	static void func(int digit, long m) {
		// 자릿수가 11자리일 때에 종료
		// 참고: 남은 자릿수를 1로 채우면, 모두 11자릿수가 된다고 가정할 수 있으므로
		if (digit == 11) {
			fm_cand.add(product(m));
			return;
		}
		
		// 다음 자리 탐색
		// min_value은 cur의 마지막 자리(숫자가 오름차순으로 정렬되어 있으므로, 다음 자리는 이전 자리보다 크거나 같을 것입니다).
		int min_value = (int)(m % 10);
		for (int i = min_value; i <= 9; i++) {
			func(digit + 1, 10L * m + 1L * i);
		}
	}
	
	// m의 각 자릿수 곱을 리턴하는 함수
	static long product(long m) {
		// m = 0 
		if (m == 0) {
			return 0;
		}
		else {
			long ans = 1;
			while (m >= 1) {
				ans *= (m % 10);
				m /= 10;
			}
			return ans;
		}
	}
}