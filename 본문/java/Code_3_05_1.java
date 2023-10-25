import java.util.*;

class Code_3_05_1 {
	public static void main(String[] args) {
		Random rd = new Random();
		int N = 10000; // N은 시행 횟수(적절하게 변경해서 사용해 주세요)
		int M = 0;
		for (int i = 1; i <= N; i++) {
			double px = rd.nextDouble(); // 0 이상, 1 미만의 랜덤한 수 생성
			double py = rd.nextDouble(); // 0 이상, 1 미만의 랜덤한 수 생성
			// 원점에서의 거리 sqrt(px * px + py * py)가
			// 1이어야 하므로, 양쪽에 제곱해서 px * px + py * py <= 1을 확인
			if (px * px + py * py <= 1.0) {
				M++;
			}
		}
		System.out.format("%.12f\n", 4.0 * M / N);
	}
}
