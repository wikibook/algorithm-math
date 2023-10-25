import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cnt = 0;
		double LIMIT = 23; // 이를 30으로 변경하면, 답을 구할 수 있음
		double Current = 0;
		
		// 하나씩 더해 나감
		while (Current < LIMIT) {
			cnt += 1;
			Current += 1.0 / cnt;
		}
		
		// 출력
		System.out.println(cnt);
	}
}
