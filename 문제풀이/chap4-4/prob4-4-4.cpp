#include <iostream>
using namespace std;

int main() {
	// 파라미터 설정/초기화
	long long cnt = 0;
	double LIMIT = 23; // 이를 30으로 변경하면, 답을 구할 수 있음
	double Current = 0;
	
	// 하나씩 더해 나감
	while (Current < LIMIT) {
		cnt += 1;
		Current += 1.0 / cnt;
	}
	
	// 답 출력
	cout << cnt << endl;
	return 0;
}