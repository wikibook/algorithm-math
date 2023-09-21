#include <iostream>
using namespace std;

int N = 100;
int A[109][109];
int X[1009], Y[1009], H[1009];

int main() {
	// 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}

	// 답을 생성
	for (int i = 1; i <= 1000; i++) {
		X[i] = rand() % N; // 0 이상 N-1 이하의 무작위 정수
		Y[i] = rand() % N; // 0 이상 N-1 이하의 무작위 정수
		H[i] = 1;
	}

	// 출력
	cout << "1000" << endl;
	for (int i = 1; i <= 1000; i++) {
		cout << X[i] << " " << Y[i] << " " << H[i] << endl;
	}
	return 0;
}
