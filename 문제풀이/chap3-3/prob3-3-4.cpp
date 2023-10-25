#include <iostream>
using namespace std;

long long N;
long long A[200009];
long long a = 0, b = 0, c = 0, d = 0; // 오버플로우를 피할 수 있게 long long 사용

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// a, b, c, d의 개수 세기
	for (int i = 1; i <= N; i++) {
		if (A[i] == 100) a += 1;
		if (A[i] == 200) b += 1;
		if (A[i] == 300) c += 1;
		if (A[i] == 400) d += 1;
	}
	
	// 출력(답은 a * d + b * c)
	cout << a * d + b * c << endl;
	return 0;
}