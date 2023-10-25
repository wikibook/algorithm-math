#include <iostream>
using namespace std;
 
const long long mod = 1000000007;
long long N;
 
int main() {
	// 입력
	cin >> N;
	
	// 답 구하기
	long long val = N * (N + 1) / 2;
	val %= mod;
	cout << val * val % mod << endl;
	return 0;
}