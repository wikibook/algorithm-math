#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	if (N % 4 == 0) cout << "Second" << endl; // 후수필승
	else cout << "First" << endl; // 선수필승
	return 0;
}