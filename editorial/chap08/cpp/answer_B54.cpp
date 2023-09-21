#include <iostream>
#include <map>
using namespace std;
 
int N, A[100009];
map<int, int> Map;
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 답을 구한다
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += Map[A[i]];
		Map[A[i]] += 1;
	}
 
	// 출력
	cout << Answer << endl;
	return 0;
}
