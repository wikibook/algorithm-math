import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] queryType = new int[Q + 1];
		int[] pos = new int[Q + 1];
		int[] x = new int[Q + 1];
		int[] l = new int[Q + 1];
		int[] r = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			queryType[i] = sc.nextInt();
			if (queryType[i] == 1) {
				pos[i] = sc.nextInt();
				x[i] = sc.nextInt();
			}
			if (queryType[i] == 2) {
				l[i] = sc.nextInt();
				r[i] = sc.nextInt();
			}
		}

		// 쿼리 처리
		SegmentTree Z = new SegmentTree(N);
		for (int i = 1; i <= Q; i++) {
			if (queryType[i] == 1) {
				Z.update(pos[i], x[i]);
			}
			if (queryType[i] == 2) {
				// 첫 번째 셀에 해당하는 반개방 구간은 [1, size + 1)
				System.out.println(Z.query(l[i], r[i], 1, Z.size + 1, 1));
			}
		}
	}

	// 세그먼트 트리를 구현한 클래스 SegmentTree
	static class SegmentTree {
		int size;
		int[] dat;
		// 요소 dat의 초기화를 수행한다(최초에는 전부 0)
		SegmentTree(int n) {
			size = 1;
			while (size < n) {
				size *= 2;
			}
			dat = new int[size * 2]; // Java에서 new로 초기화한 배열의 요소는 0이 된다는 점에 유의하세요.
		}
		// 쿼리 1에 대한 처리
		void update(int pos, int x) {
			pos += size - 1;
			dat[pos] = x;
			while (pos >= 2) {
				pos /= 2;
				dat[pos] = Math.max(dat[pos * 2], dat[pos * 2 + 1]);
			}
		}
		// 쿼리 2에 대한 처리
		// u는 현재의 셀 번호, [a, b)는 셀에 대응하는 반개구간, [l, r)은 구할 반개구간
		int query(int l, int r, int a, int b, int u) {
			if (r <= a || b <= l) {
				return -1000000000; // 전혀 포함되지 않는 경우
			}
			if (l <= a && b <= r) {
				return dat[u];      // 완전히 포함된 경우
			}
			int m = (a + b) / 2;
			int answerL = query(l, r, a, m, u * 2);
			int answerR = query(l, r, m, b, u * 2 + 1);
			return Math.max(answerL, answerR);
		}
	}
}