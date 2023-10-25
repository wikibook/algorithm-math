#include <iostream>
#include <string>
using namespace std;

int N;
string Answer = ""; // string은 문자열 자료형

int main() {
	cin >> N; // 입력 부분
	while (N >= 1) {
		// N % 2는 N를 2로 나눈 나머지(예: N = 13의 경우 1)
		// N / 2는 N를 2로 나눈 몫(예:N = 13의 경우 6)
		if (N % 2 == 0) Answer = "0" + Answer;
		if (N % 2 == 1) Answer = "1" + Answer;
		N = N / 2;
	}
	cout << Answer << endl; // 출력 부분
	return 0;
}