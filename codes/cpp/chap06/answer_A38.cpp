#include <iostream>
#include <algorithm>
using namespace std;

int D, N;
int L[10009], R[10009], H[10009], LIM[10009];

int main() {
	// 입력
	cin >> D >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> H[i];

	// 배열 초기화(1일은 24시간)
	for (int i = 1; i <= D; i++) LIM[i] = 24;

	// 상한 값을 구한다
	for (int i = 1; i <= N; i++) {
		for (int j = L[i]; j <= R[i]; j++) LIM[j] = min(LIM[j], H[i]);
	}

	// 답을 출력
	int Answer = 0;
	for (int i = 1; i <= D; i++) Answer += LIM[i];
	cout << Answer << endl;
	return 0;
}
