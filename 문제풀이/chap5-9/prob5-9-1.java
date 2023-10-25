import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long Answer = 0;
		
		// 10000원으로 지불
		Answer += (N / 10000); N %= 10000;
		
		// 5000원으로 지불
		Answer += (N / 5000); N %= 5000;
		
		// 1000원으로 지불
		Answer += (N / 1000); N %= 1000;
		
		// 출력
		System.out.println(Answer);
	}
}