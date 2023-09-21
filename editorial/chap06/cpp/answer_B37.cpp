#include <iostream>
#include <string>
using namespace std;
 
long long N;
long long R[18][10]; // R[i][j]는 '아래에서 i번째 자리가 j가 되는 N 이하의 정수 개수'입니다.
long long Power10[18];
 
int main() {
	// 입력
	cin >> N;
 
	// 10의 N 제곱 찾기
	Power10[0] = 1;
	for (int i = 1; i <= 16; i++) Power10[i] = 10LL * Power10[i - 1];
 
	// R[i][j]의 값 계산
	for (int i = 0; i <= 15; i++) {
		// 아래에서 i 번째 자리의 숫자를 찾습니다.
		long long Digit = (N / Power10[i]) % 10LL;
 
		// R[i][j] 값 구하기
		for (int j = 0; j < 10; j++) {
			if (j < Digit) {
				R[i][j] = (N / Power10[i + 1] + 1LL) * Power10[i];
			}
			if (j == Digit) {
				R[i][j] = (N / Power10[i + 1]) * Power10[i] + (N % Power10[i]) + 1LL;
			}
			if (j > Digit) {
				R[i][j] = (N / Power10[i + 1]) * Power10[i];
			}
		}
	}
 
	// 답을 구한다
	long long Answer = 0;
	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j < 10; j++) Answer += 1LL * j * R[i][j];
	}
 
	// 출력
	cout << Answer << endl;
	return 0;
}
