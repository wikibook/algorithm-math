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
 
// 입력으로 주어지는 변수・답변
int N, M, A[100009], B[100009];
int Q, QueryType[100009], x[100009], u[100009], v[100009];
string Answer[100009];
 
// 기타 변수
UnionFind UF;
bool cancelled[100009];
 
int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> QueryType[i];
		if (QueryType[i] == 1) cin >> x[i];
		if (QueryType[i] == 2) cin >> u[i] >> v[i];
	}
 
	// 먼저 운행이 중단된 노선을 찾아보자
	for (int i = 1; i <= M; i++) cancelled[i] = false;
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 1) cancelled[x[i]] = true;
	}
 
	// Union-Find의 초기화(그날의 마지막 상태)
	UF.init(N);
	for (int i = 1; i <= M; i++) {
		if (cancelled[i] == false && UF.same(A[i], B[i]) == false) {
			UF.unite(A[i], B[i]);
		}
	}
 
	// 역방향 쿼리 처리
	for (int i = Q; i >= 1; i--) {
		if (QueryType[i] == 1) {
			// A[x[i]]역과 B[x[i]]역을 연결하는 노선 개통
			if (UF.same(A[x[i]], B[x[i]]) == false) UF.unite(A[x[i]], B[x[i]]);
		}
		if (QueryType[i] == 2) {
			if (UF.same(u[i], v[i]) == true) Answer[i] = "Yes";
			else Answer[i] = "No";
		}
	}
 
	// 출력
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 2) cout << Answer[i] << endl;
	}
	return 0;
}
