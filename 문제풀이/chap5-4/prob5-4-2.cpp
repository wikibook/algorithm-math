#include <iostream>
using namespace std;
 
int H, W, A[2009][2009];
int gyou[2009]; // 행의 총합
int retu[2009]; // 열의 총합
int Answer[2009][2009];
 
int main() {
	// 입력
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> A[i][j];
	}
	
	// 행의 총합 계산하기
	for (int i = 1; i <= H; i++) {
		gyou[i] = 0;
		for (int j = 1; j <= W; j++) gyou[i] += A[i][j];
	}
	
	// 열의 총합 계산하기
	for (int j = 1; j <= W; j++) {
		retu[j] = 0;
		for (int i = 1; i <= H; i++) retu[j] += A[i][j];
	}
	
	// 각 칸의 답 계산하기
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Answer[i][j] = gyou[i] + retu[j] - A[i][j];
		}
	}
	
	// 공백으로 구분해서 출력하기
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (j >= 2) cout << " ";
			cout << Answer[i][j];
		}
		cout << endl;
	}
	return 0;
}