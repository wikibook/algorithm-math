import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해 Scanner 대신 BufferedReader를 사용)
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		int[] C = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
		}

		// 변의 길이가 작은 순서로 정렬하기
		// (책 속 코드에서 edgeList는 (길이, 변 번호) 쌍으로 되어 있지만, 여기서는 에지 번호만 기록된 배열을 길이가 작은 순으로 정렬하는 방식을 취합니다.)
		Integer[] edgeList = new Integer[M];
		for (int i = 0; i < M; i++) {
			edgeList[i] = i + 1;
		}
		Arrays.sort(
			edgeList,
			new Comparator<Integer>() {
				@Override
				public int compare(Integer id1, Integer id2) {
					return C[id1] - C[id2]; // C[id1] < C[id2] 일 때 id1이 id2보다 앞에 오도록 한다.
				}
			}
		);
		
		// 최소 전역 트리를 구한다
		int answer = 0;
		UnionFind uf = new UnionFind(N);
		for (int i = 0; i < M; i++) {
			int idx = edgeList[i];
			if (!uf.same(A[idx], B[idx])) {
				uf.unite(A[idx], B[idx]);
				answer += C[idx];
			}
		}

		// 답 출력
		System.out.println(answer);
	}
	
	// Union-Find 트리를 구현한 클래스 UnionFind
	static class UnionFind {
		int n;
		int[] par;
		int[] size;

		// N 노드의 Union-Find를 작성
		public UnionFind(int n) {
			this.n = n;
			par = new int[n + 1];
			size = new int[n + 1];
			Arrays.fill(par, -1); // 최초에는 부모가 없다 (par[i] = -1)
			Arrays.fill(size, 1); // 최초에는 그룹의 노드 수가 1 (size[i] = 1)
		}

		// 노드 x의 루트를 반환하는 함수
		int root(int x) {
			while (true) {
				if (par[x] == -1) {
					break;  // 1개 앞(부모)이 없으면 여기가 루트
				}
				x = par[x]; // 1 개 앞(부모)으로 진행한다
			}
			return x;
		}

		// 요소 u와 v를 통합하는 함수
		void unite(int u, int v) {
			int rootU = root(u);
			int rootV = root(v);
			if (rootU == rootV) {
				return; // u와 v가 같은 그룹일 때는 처리를 수행하지 않는다
			}
			if (size[rootU] < size[rootV]) {
				par[rootU] = rootV;
				size[rootV] += size[rootU];
			}
			else {
				par[rootV] = rootU;
				size[rootU] += size[rootV];
			}
		}

		//요소 u와 v가 같은 그룹인지 반환하는 함수
		boolean same(int u, int v) {
			return root(u) == root(v);
		}
	}
}