#include <iostream>
using namespace std;

int Q, X[10009], N = 300000; // X[i] <= 300000이므로 300000 이하의 소수를 열거
bool Deleted[300009]; // 정수 x가 지워진 경우에 한해 Deleted[x]=true

int main() {
	// 입력, 배열 초기화
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];
	for (int i = 2; i <= N; i++) Deleted[i] = false;

	// 에라토스테네스의 체(i는 √N 이하의 가장 큰 정수까지 반복한다)
	for (int i = 2; i * i <= N; i++) {
		if (Deleted[i] == true) continue;
		for (int j = i * 2; j <= N; j += i) Deleted[j] = true;
	}

	// 출력
	for (int i = 1; i <= Q; i++) {
		if (Deleted[X[i]] == false) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
