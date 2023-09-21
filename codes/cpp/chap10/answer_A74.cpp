#include <iostream>
using namespace std;

int N, P[109][109];
int X[109], InversionX = 0;
int Y[109], InversionY = 0;

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> P[i][j];
			if (P[i][j] != 0) { X[i] = P[i][j]; Y[j] = P[i][j]; }
		}
	}

	// X의 전도 수, Y의 전도 수를 구한다
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (X[i] > X[j]) InversionX += 1;
			if (Y[i] > Y[j]) InversionY += 1;
		}
	}

	// 출력
	cout << InversionX + InversionY << endl;
	return 0;
}
