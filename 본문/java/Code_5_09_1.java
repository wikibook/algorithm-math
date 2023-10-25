import java.util.*;

class Code_5_09_1 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 지불 방법 시뮬레이션
		long answer = 0;
		while (N >= 10000) {
			N -= 10000; // 10000원 이상이라면 10000원으로 지불할 수 있는 만큼 지불
			answer += 1;
		}
		while (N >= 5000) {
			N -= 5000; // 5000원 이상이라면 5000원으로 지불할 수 있는 만큼 지불
			answer += 1;
		}
		while (N >= 1) {
			N -= 1000; // 남은 금액은 1000원으로 지불
			answer += 1;
		}
		
		// 답 출력
		System.out.println(answer);
	}
}
