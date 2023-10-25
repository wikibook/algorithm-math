#include <iostream>
using namespace std;

int main() {
	// 입력
	long long N, Answer = 0;
	cin >> N;

	// 지불 방법 시뮬레이션 → 답 출력
	while (N >= 10000) { N -= 10000; Answer += 1; }
	while (N >= 5000) { N -= 5000; Answer += 1; }
	while (N >= 1) { N -= 1000; Answer += 1; }
	cout << Answer << endl;
	return 0;
}