#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		cout << i << endl; // i를 약수로 추가
		if (i != N / i) {
			cout << N / i << endl; // i ≠ N/i라면, N/i도 약수에 추가
		}
	}
	return 0;
}