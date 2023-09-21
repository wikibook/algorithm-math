#include <iostream>
#include <queue>
using namespace std;
 
int N, X;
char A[100009];
queue<int> Q;
 
int main() {
	// 입력
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 시뮬레이션
	Q.push(X); A[X] = '@';
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		if (pos - 1 >= 1 && A[pos - 1] == '.') {
			A[pos - 1] = '@';
			Q.push(pos - 1);
		}
		if (pos + 1 <= N && A[pos + 1] == '.') {
			A[pos + 1] = '@';
			Q.push(pos + 1);
		}
	}
 
	// 출력
	for (int i = 1; i <= N; i++) cout << A[i];
	cout << endl;
	return 0;
}
