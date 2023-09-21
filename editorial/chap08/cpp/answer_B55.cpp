#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
long long Q, QueryType[100009], x[100009];
set<long long> Set1, Set2;
 
// r 이하의 최대값을 반환한다
long long GetDown(long long r) {
	auto itr = Set2.lower_bound(-r);
 
	// r 이하가 존재하지 않으면 매우 작은 값을 반환한다
	if (itr == Set2.end()) return -100000000000000LL;
 
	// 존재하는 경우
	return -(*itr);
}
 
//  r 이상의 최소값을 반환한다
long long GetUp(long long r) {
	auto itr = Set1.lower_bound(r);
 
	// r보다 큰 값이 존재하지 않으면 매우 큰 값을 반환한다
	if (itr == Set1.end()) return 100000000000000LL;
 
	// 존재하는 경우
	return (*itr);
}
 
int main() {
	// 입력
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> QueryType[i] >> x[i];
 
	// 쿼리 처리
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 1) {
			Set1.insert(x[i]);
			Set2.insert(-x[i]);
		}
		if (QueryType[i] == 2) {
			long long v1 = GetDown(x[i]);
			long long v2 = GetUp(x[i]);
			long long Answer = min(x[i] - v1, v2 - x[i]);
			if (Answer == 100000000000000LL) cout << "-1" << endl;
			else cout << Answer << endl;
		}
	}
	return 0;
}
