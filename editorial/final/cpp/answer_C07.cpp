#include <iostream>
#include <algorithm>
using namespace std;

long long N, C[100009], S[100009];
long long Q, X[100009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];

	// C[i] 작은 순서로 정렬
	sort(C + 1, C + N + 1);

	// 누적 합계 S[i]를 취한다
	// S[i]는 'i 개 상품을 구매할 때 최소 금액'
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + C[i];

	// 질문에 답한다
	for (int i = 1; i <= Q; i++) {
		int pos = upper_bound(S, S + N + 1, X[i]) - S;
		cout << pos - 1 << endl;
	}
	return 0;
}
