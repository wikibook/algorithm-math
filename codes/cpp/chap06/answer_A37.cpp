#include <iostream>
using namespace std;

long long N, M, B;
long long A[200009], C[200009];

int main() {
	// 입력
	cin >> N >> M >> B;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= M; j++) cin >> C[j];

	// 답 계산
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += A[i] * M;
	Answer += B * N * M;
	for (int j = 1; j <= M; j++) Answer += C[j] * N;

	// 출력
	cout << Answer << endl;
	return 0;
}
