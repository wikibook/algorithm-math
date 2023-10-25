// 이 코드는 깊이 우선 탐색(DFS)를 스택으로 구현한 예입니다.
// 스택은 "가장 위에 요소를 추가한다", "가장 위의 요소를 확인한다", "가장 위의 요소를 꺼낸다"라는 3가지 조작을 할 수 있는 자료구조입니다.
// 깊이 우선 탐색 부분은 코드 4.5.3의 queue를 stack으로 변경한 것을 기반으로 작성했습니다.

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];

int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 깊이 우선 탐색 초기화
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	stack<int> S; // 스택 S 정의
	visited[1] = true;
	S.push(1); // S에 1을 추가

	// 깊이 우선 탐색
	while (!S.empty()) {
		int pos = S.top(); // S의 앞부분 확인하기
		S.pop(); // S의 앞부분 추출하기
		for (int nex : G[pos]) {
			if (visited[nex] == false) {
				visited[nex] = true;
				S.push(nex); // S에 nex를 추가
			}
		}
	}

	// 연결되어 있는지 판정(Answer=true라면 연결됨)
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) {
		cout << "The graph is connected." << endl;
	}
	else {
		cout << "The graph is not connected." << endl;
	}
	return 0;
}