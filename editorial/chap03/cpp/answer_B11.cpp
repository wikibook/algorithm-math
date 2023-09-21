#include <iostream>
#include <algorithm>
using namespace std;
 
int N, A[100009];
int Q, X[100009];
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];
 
	// 배열 X 정렬
	sort(A + 1, A + N + 1);
 
	// 질문에 답한다
	for (int i = 1; i <= Q; i++) {
		int pos1 = lower_bound(A + 1, A + N + 1, X[i]) - A;
		cout << pos1 - 1 << endl;
	}
	return 0;
}
