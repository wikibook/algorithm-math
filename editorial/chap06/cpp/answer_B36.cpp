#include <iostream>
#include <string>
using namespace std;
 
int N, K;
string S;
 
int main() {
	// 입력
	cin >> N >> K;
	cin >> S;
 
	// ON으로 되어 있는 것의 개수를 센다
	int numON = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') numON += 1;
	}
 
	// 답을 출력
	if (numON % 2 == K % 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
