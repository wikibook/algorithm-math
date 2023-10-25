#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// 입력
	long long a, b, c;
	cin >> a >> b >> c;
	
	// c = 1 때의 조건 분기
	if (c == 1) {
		cout << "No" << endl;
		return 0;
	}
	
	// 좌변 계산(c의 b 제곱)
	long long v = 1;
	for (long long i = 1; i <= b; i++) {
		if (a / c < v) {
			// 이 조건 분기는 a < (v * c)를 변경한 것입니다.
			// 조건을 변경한 이유는 c가 10^18를 넘을수도 있기 때문입니다.
			// a < v * c로 하면, 최악의 경우 v * c = 10^36가 되어 오버플로가 발생합니다.
			cout << "Yes" << endl;
			return 0;
		}
		v *= c;
	}
	
	// 반복이 끝나지 않는 경우
	cout << "No" << endl;
	return 0;
}