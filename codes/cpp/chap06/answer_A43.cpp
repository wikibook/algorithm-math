#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int A[200009]; char B[200009];

int main() {
	// 입력
	cin >> N >> L;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	// 답을 구한다
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (B[i] == 'E') Answer = max(Answer, L - A[i]);
		if (B[i] == 'W') Answer = max(Answer, A[i]);
	}
	cout << Answer << endl;
	return 0;
}
