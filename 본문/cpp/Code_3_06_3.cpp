#include <iostream>
using namespace std;

int func(int N) {
	if (N == 1) return 1; // 이처럼 재귀 함수를 끝내는 경우를 "베이스 케이스"라고 부릅니다.
	return func(N - 1) * N;
}

int main() {
	int N;
	cin >> N;
	cout << func(N) << endl;
	return 0;
}