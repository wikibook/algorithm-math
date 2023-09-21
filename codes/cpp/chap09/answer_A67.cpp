#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Find 클래스의 구현은 9.6절 참조
int N, M;
int A[100009], B[100009], C[100009];
UnionFind UF;

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];

	// 에지를 길이의 오름차순으로 정렬한다
	vector<pair<int, int>> EdgeList;
	for (int i = 1; i <= M; i++) EdgeList.push_back(make_pair(C[i], i));
	sort(EdgeList.begin(), EdgeList.end());

	// 최소 전역 트리를 구한다
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
