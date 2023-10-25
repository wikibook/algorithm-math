#include <iostream>
using namespace std;
 
int main() {
	// 입력
	long long N;
	cin >> N;
	
	// N = 2^k-1 형태로 나타낼 수 있는지 확인하기
	bool flag = false;
	for (int k = 1; k <= 60; k++) {
		if (N == (1LL << k) - 1LL) flag = true;
	}
	
	// 출력
	if (flag == true) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}