#include <iostream>
using namespace std;

int N, K, A[59];
int sum = 0; // A[1] + A[2] + ... + A[N]의 값

int main() {
	// 입력 → 수열 요소의 총합 sum 구하기
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) sum += A[i];

	// 답 출력
	if (sum % 2 != K % 2) cout << "No" << endl;
	else if (sum > K) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}