#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 입력
	long long N;
	cin >> N;

	// 약수 열거
	vector<long long> Yakusuu;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			Yakusuu.push_back(i);
			if (i != N / i) Yakusuu.push_back(N / i);
		}
	}

	// 작은 순으로 정렬
	sort(Yakusuu.begin(), Yakusuu.end());

	// 출력
	for (int i = 0; i < Yakusuu.size(); i++) {
		cout << Yakusuu[i] << endl;
	}
	return 0;
}
