import java.util.*;

class Code_3_08_1 {
	public static void main(String[] args) {
		// 입력(주의: 이번 예제에서 배열은 A[0]부터 A[N-1]까지 차례대로 입력됩니다. 인덱스를 0부터 시작하는 것을 0-인덱스라고 부릅니다).
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long X = sc.nextLong();
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
		}
		
		// 배열 정렬
		Arrays.sort(A);
		
		// 이진 탐색
		String answer = "No";
		int left = 0, right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == X) {
				answer = "Yes";
				break;
			}
			if (A[mid] > X) {
				// 탐색 범위를 앞부분으로 변경
				right = mid - 1;
			}
			if (A[mid] < X) {
				// 탐색 범위를 뒷부분으로 변경
				left = mid + 1;
			}
		}
		
		// 답 출력
		System.out.println(answer);
	}
}
