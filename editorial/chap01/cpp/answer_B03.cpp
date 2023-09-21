#include <iostream>
using namespace std;
 
int main() {
	// 입력
	int N, A[109];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 답을 구한다
	bool Answer = false;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (A[i] + A[j] + A[k] == 1000) Answer = true;
			}
		}
	}
	
	// 출력
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
