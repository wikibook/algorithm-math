#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L[300009], R[300009];
vector<pair<int, int>> tmp; // 영화를 정렬하기 위한 임시 변수

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
		tmp.push_back(make_pair(R[i], L[i]));
	}

	// R의 오름차순으로 정렬
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i <= N; i++) {
		R[i] = tmp[i - 1].first;
		L[i] = tmp[i - 1].second;
	}

	// 종료 시각이 빠른 것부터 탐욕적으로 취해 간다(CurrentTime은 현재 시각)
	int CurrentTime = 0, Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= L[i]) {
			CurrentTime = R[i];
			Answer += 1;
		}
	}
	cout << Answer << endl;
	return 0;
}
