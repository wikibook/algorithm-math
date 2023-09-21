#include <iostream>
#include <vector>
using namespace std;
 
int N, M, A[100009], B[100009];
vector<int> G[100009];
 
int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // '노드 A[i]에 인접한 노드'로 B[i]를 추가
		G[B[i]].push_back(A[i]); // '노드 B[i]에 인접한 노드'로 A[i]를 추가
	}
 
	// 차수(= 친구 수)가 최대가 되는 학생의 수를 구한다
	int MaxFriends = 0; // 최대 친구 수
	int MaxID = 0;      // 번호
	for (int i = 1; i <= N; i++) {
		if (MaxFriends < (int)G[i].size()) {
			MaxFriends = (int)G[i].size();
			MaxID = i;
		}
	}
 
	// 출력
	cout << MaxID << endl;
	return 0;
}
