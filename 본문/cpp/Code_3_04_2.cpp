#include <iostream>
using namespace std;

int N, P[59], Q[59];
double Answer = 0.0;

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i] >> Q[i];

	// 답 계산 → 답 출력
	for (int i = 1; i <= N; i++) {
		Answer += 1.0 * Q[i] / P[i];
	}
	printf("%.12lf\n", Answer);
	return 0;
}