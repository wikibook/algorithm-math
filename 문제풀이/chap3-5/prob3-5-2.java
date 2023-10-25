import java.util.*;

class Main {
	public static void main(String[] args) {
		Random rd = new Random();
		int N = 1000000; // N은 시행 횟수(적절하게 변경해서 사용해 주세요)
		int M = 0;
		for (int i = 1; i <= N; i++) {
			double px = 6.0 * rd.nextDouble();
			double py = 9.0 * rd.nextDouble();
			
			// 점 (3, 3)과의 거리입니다. 이 값이 3 이하라면, 반지름 3인 원 내부에 포함됩니다.
			double dist_33 = Math.sqrt((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0));
			
			// 점 (3, 7)과의 거리입니다. 이 값이 2 이하라면, 반지름 2인 원 내부에 포함됩니다.
			double dist_37 = Math.sqrt((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0));
			
			if (dist_33 <= 3.0 || dist_37 <= 2.0) M += 1;
		}
		System.out.println(M);
	}
}