#include <iostream>
using namespace std;

int main() {
	long long N;
	long long Answer = 1;
	cin >> N;
	for (int i = 2; i <= N; i++) Answer *= i; // Answer에 i를 곱함
	cout << Answer << endl;
	return 0;
}