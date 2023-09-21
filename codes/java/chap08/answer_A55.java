import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int Q = sc.nextInt();
		int[] queryType = new int[Q + 1];
		int[] x = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			queryType[i] = sc.nextInt();
			x[i] = sc.nextInt();
		}

		// 쿼리 처리
		TreeSet<Integer> S = new TreeSet<>();
		for (int i = 1; i <= Q; i++) {
			if (queryType[i] == 1) {
				S.add(x[i]);
			}
			if (queryType[i] == 2) {
				S.remove(x[i]);
			}
			if (queryType[i] == 3) {
				Integer res = S.higher(x[i] - 1); // higher 함수는 '인수보다 큰 것 중 가장 작은 요소'를 반환하므로 인수를 x[i] - 1로 설정
				System.out.println(res != null ? res : -1);
			}
		}
	}
}