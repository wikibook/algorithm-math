#include <iostream>
#include <string>
using namespace std;
 
int main() {
	// 입력
	string N;
	cin >> N;
	
	// 답을 구한다
	int Answer = 0;
	for (int i = 0; i < N.size(); i++) {
		int keta;
		int kurai = (1 << (N.size() - 1 - i));
		if (N[i] == '0') keta = 0;
		if (N[i] == '1') keta = 1;
		Answer += keta * kurai;
	}
	
	// 출력
	cout << Answer << endl;
	return 0;
}
