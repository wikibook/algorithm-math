#include <iostream>
#include <vector>
#include <algorithm>
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
 
// Union-Find 클래스의 구현은 9.6절 참조
int N, M;
int A[100009], B[100009], C[100009];
UnionFind UF;
 
int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
 
	// 에지가 긴 순서대로 정렬하기
	vector<pair<int, int>> EdgeList;
	for (int i = 1; i <= M; i++) EdgeList.push_back(make_pair(C[i], i));
	sort(EdgeList.begin(), EdgeList.end());
	reverse(EdgeList.begin(), EdgeList.end()); // 문제 A67과 다른 유일한 부분
 
	// 최대 전체 면적의 나무를 찾는다
	int Answer = 0; UF.init(N);
	for (int i = 0; i < EdgeList.size(); i++) {
		int idx = EdgeList[i].second;
		if (UF.same(A[idx], B[idx]) == false) {
			UF.unite(A[idx], B[idx]);
			Answer += C[idx];
		}
	}
	cout << Answer << endl;
	return 0;
}
