#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// "배열 A에 있는 카드 중 몇 개를 선택했을 때의 합계"로 생각되는 것을 열거한다
// 비트 완전 탐색 사용
vector<long long> Enumerate(vector<long long> A) {
	vector<long long> SumList;
	for (int i = 0; i < (1 << A.size()); i++) {
		long long sum = 0; // 현재 합계 값
		for (int j = 0; j < A.size(); j++) {
			int wari = (1 << j);
			if ((i / wari) % 2 == 1) sum += A[j];
		}
		SumList.push_back(sum);
	}
	return SumList;
}
 
long long N, K;
long long A[39];
 
int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 카드를 반으로 나눈다
	vector<long long> L1, L2;
	for (int i = 1; i <= N / 2; i++) L1.push_back(A[i]);
	for (int i = N / 2 + 1; i <= N; i++) L2.push_back(A[i]);
 
	// 각각에 대해 '가능한 카드의 합계'를 모두 열거한다
	vector<long long> Sum1 = Enumerate(L1);
	vector<long long> Sum2 = Enumerate(L2);
	sort(Sum1.begin(), Sum1.end());
	sort(Sum2.begin(), Sum2.end());
 
	// 바이너리 서치에서 Sum1[i] + Sum2[j] = K가 되는 것이 존재하는지 찾기
	for (int i = 0; i < Sum1.size(); i++) {
		int pos = lower_bound(Sum2.begin(), Sum2.end(), K - Sum1[i]) - Sum2.begin();
		if (pos < Sum2.size() && Sum2[pos] == K - Sum1[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
