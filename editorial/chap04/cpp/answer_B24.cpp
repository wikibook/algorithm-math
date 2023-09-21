#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, X[100009], Y[100009];
int LEN, L[100009];
 
// 배열 A의 가장 긴 증가부 분절(LIS)의 길이를 계산한다.
// 배열 dp를 사용하지 않는 구현방법을 이용하고 있다
int Get_LISvalue(vector<int> A) {
	LEN = 0;
	for (int i = 1; i <= A.size(); i++) L[i] = 0;
 
	// 동적 계획 알고리즘
	for (int i = 0; i < A.size(); i++) {
		int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
		L[pos] = A[i];
		if (pos > LEN) LEN += 1;
	}
	return LEN;
}
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
 
	// 정렬
	vector<pair<int, int>> tmp;
	for (int i = 1; i <= N; i++) tmp.push_back(make_pair(X[i], -Y[i]));
	sort(tmp.begin(), tmp.end());
	
	// LIS를 찾아야 하는 배열은?
	vector<int> A;
	for (int i = 0; i < tmp.size(); i++) {
		A.push_back(-tmp[i].second);
	}
 
	// 출력
	cout << Get_LISvalue(A) << endl;
	return 0;
}
