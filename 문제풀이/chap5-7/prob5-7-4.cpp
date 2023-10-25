#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long X[200009], Y[200009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	
	// 배열 정렬하기
	sort(X + 1, X + N + 1);
	sort(Y + 1, Y + N + 1);
	
	// Part1의 답(x 좌표 차의 절댓값 총합)
	long long Part1 = 0;
	for (int i = 1; i <= N; i++) Part1 += X[i] * (-N + 2LL * i - 1LL);
	
	// Part2의 답(y 좌표 차의 절댓값 총합)
	long long Part2 = 0;
	for (int i = 1; i <= N; i++) Part2 += Y[i] * (-N + 2LL * i - 1LL);
	
	// 출력
	cout << Part1 + Part2 << endl;
	return 0;
}