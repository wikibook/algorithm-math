import java.util.*;

class Code_3_06_1 {
	public static void main(String[] args) {
		// 입력(예를 들어서 N = 5, A = [3, 1, 4, 1, 5]를 입력하면)
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 1; i <= N; i++) {
			A[i - 1] = sc.nextInt();
		}
		
		// 배열A 전체를 정렬
		Arrays.sort(A);
		
		// 출력(1, 1, 3, 4, 5 순서로 출력됨)
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i - 1]);
		}
	}
}
