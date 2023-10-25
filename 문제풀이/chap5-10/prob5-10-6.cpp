#include <iostream>
#include <set>
using namespace std;
 
// f(m)으로 얻을 수 있는 후보
// set 자료형과 관련된 내용은 따로 검색해서 찾아보면 좋습니다!
set<long long> fm_cand;
 
// m의 각 자릿수 곱을 리턴하는 함수
long long product(long long m) {
	if (m == 0) {
		return 0;
	}
	else {
		long long ans = 1;
		while (m >= 1) {
			ans *= (m % 10);
			m /= 10;
		}
		return ans;
	}
}

void func(int digit, long long m) {
	// 자릿수가 11자리일 때에 종료
	// 참고: 남은 자릿수를 1로 채우면, 모두 11자릿수가 된다고 가정할 수 있으므로
	if (digit == 11) {
		fm_cand.insert(product(m));
		return;
	}
	
	// 다음 자리 탐색
	// min_value은 cur의 마지막 자리(숫자가 오름차순으로 정렬되어 있으므로, 다음 자리는 이전 자리보다 크거나 같을 것입니다).
	int min_value = (m % 10);
	for (int i = min_value; i <= 9; i++) {
		// 10 * m + i는 m 뒤에 숫자 i를 붙이는 것
		func(digit + 1, 10 * m + i);
	}
}
 
int main() {
	// f(m) 후보 나열
	func(0, 0);
 
	// 입력
	long long N, B;
	cin >> N >> B;
 
	// m - f(m) == B이 되는지 확인
	long long Answer = 0;
	for (long long fm : fm_cand) {
		long long m = fm + B;
		long long prod_m = product(m);
		if (m - prod_m == B && m <= N) {
			Answer += 1;
		}
	}
 
	// 출력
	cout << Answer << endl;
	return 0;
}