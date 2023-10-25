#include <iostream>
#include <algorithm>
using namespace std;

int N, L[2009], R[2009];
int Current_Time = 0, Answer = 0; // Current_Time은 현재 시각(직전에 보았던 영화의 종료 시각)

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 영화 선택 시뮬레이션
	// 볼 수 있는 영화 중 종료 시간 최솟값 min_endtime은 일단 1000000(INF로 설정)처럼 나올 수 없는 값으로 설정합니다.
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < Current_Time) continue;
			min_endtime = min(min_endtime, R[i]);
		}
		if (min_endtime == 1000000) break;
		Current_Time = min_endtime;
		Answer += 1;
	}

	// 답 출력
	cout << Answer << endl;
	return 0;
}