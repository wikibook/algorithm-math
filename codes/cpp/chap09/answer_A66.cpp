#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
	int par[100009];
	int siz[100009];

	// N 노드의 Union-Find를 작성
	void init(int N) {
		for (int i = 1; i <= N; i++) par[i] = -1; // 최초에는 부모가 없다
		for (int i = 1; i <= N; i++) siz[i] = 1; // 최초에는 그룹의 노드 수가 1
	}

	// 노드 x의 루트를 반환하는 함수
	int root(int x) {
		while (true) {
			if (par[x] == -1) break; // 1개 앞(부모)이 없으면 여기가 루트
			x = par[x]; // 1 개 앞(부모)으로 진행한다
		}
		return x;
	}

	// 요소 u와 v를 통합하는 함수
	void unite(int u, int v) {
		int RootU = root(u);
		int RootV = root(v);
		if (RootU == RootV) return; // u와 v가 같은 그룹일 때는 처리를 수행하지 않는다
		if (siz[RootU] < siz[RootV]) {
			par[RootU] = RootV;
			siz[RootV] = siz[RootU] + siz[RootV];
		}
		else {
			par[RootV] = RootU;
			siz[RootU] = siz[RootU] + siz[RootV];
		}
	}

	//요소 u와 v가 같은 그룹인지 반환하는 함수
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int N, Q;
int Query[100009], u[100009], v[100009];

int main() {
	// 입력
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) cin >> Query[i] >> u[i] >> v[i];

	// 쿼리 처리
	UnionFind UF;
	UF.init(N);
	for (int i = 1; i <= Q; i++) {
		if (Query[i] == 1) {
			UF.unite(u[i], v[i]);
		}
		if (Query[i] == 2) {
			if (UF.same(u[i], v[i]) == true) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
