#include <iostream>
using namespace std;

int main() {
	// 입력
	long long N, A[100009]; char T[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> A[i];

	// 출력(Answer는 현재 칠판의 수)
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (T[i] == '+') Answer += A[i];
		if (T[i] == '-') Answer -= A[i];
		if (T[i] == '*') Answer *= A[i];
		cout << Answer % 10000 << endl;
	}
	return 0;
}
