import java.util.*;

class Code_3_06_2 {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 선택 정렬
		for (int i = 1; i <= N - 1; i++) {
			int minPosition = i;
			int minValue = A[i];
			for (int j = i + 1; j <= N; j++) {
				if (A[j] < minValue) {
					minPosition = j; // minPosition는 최솟값의 인덱스(1~N)
					minValue = A[j]; // minValue는 현재 시점의 최솟값
				}
			}
			// 다음 3줄로 A[i]와 A[minPosition]를 스왑
			int temp = A[i];
			A[i] = A[minPosition];
			A[minPosition] = temp;
		}
		
		// 출력
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i]);
		}
	}
}
