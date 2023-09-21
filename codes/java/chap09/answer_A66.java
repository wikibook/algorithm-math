import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 입력(빠른 입출력을 위해 Scanner 대신 BufferedReader를 사용)
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		int[] query = new int[Q + 1];
		int[] u = new int[Q + 1];
		int[] v = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			st = new StringTokenizer(buff.readLine());
			query[i] = Integer.parseInt(st.nextToken());
			u[i] = Integer.parseInt(st.nextToken());
			v[i] = Integer.parseInt(st.nextToken());
		}
		
		// 쿼리 처리
		// (빠른 출력을 위해 System.out.println이 아닌 PrintWriter를 사용)
		PrintWriter output = new PrintWriter(System.out);
		UnionFind uf = new UnionFind(N);
		for (int i = 1; i <= Q; i++) {
			if (query[i] == 1) {
				uf.unite(u[i], v[i]);
			}
			if (query[i] == 2) {
				if (uf.same(u[i], v[i])) {
					output.println("Yes");
				}
				else {
					output.println("No");
				}
			}
		}
		output.flush();
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