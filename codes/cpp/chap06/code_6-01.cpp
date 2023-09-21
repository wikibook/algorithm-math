#include <iostream>
#include <algorithm>
using namespace std;

int N, L[300009], R[300009];

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 종료 시각이 빠른 것부터 탐욕적으로 취해 간다(CurrentTime은 현재 시각)
	int CurrentTime = 0, Answer = 0;
	while (true) {
		int Min_EndTime = 999999; // 다음으로 선택할 영화의 종료 시각
		for (int i = 1; i <= N; i++) {
			if (L[i] < CurrentTime) continue;
			Min_EndTime = min(Min_EndTime, R[i]);
		}

		// 다음으로 선택할 영화가 있다/없다에 대응해 처리를 수행한다
		if (Min_EndTime == 999999) break;
		CurrentTime = Min_EndTime; Answer += 1;
	}
	cout << Answer << endl;
	return 0;
}
