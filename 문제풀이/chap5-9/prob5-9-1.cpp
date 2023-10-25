#include <iostream>
using namespace std;

int main() {
	// 입력
	long long N, Answer = 0;
	cin >> N;
	
	// 10000원으로 지불
	Answer += (N / 10000); N %= 10000;
	
	// 5000원으로 지불
	Answer += (N / 5000); N %= 5000;
	
	// 1000원으로 지불
	Answer += (N / 1000); N %= 1000;
	
	// 답 출력
	cout << Answer << endl;
	return 0;
}