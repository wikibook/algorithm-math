#include <stdio.h>
#include <stdbool.h>

int N, L[2009], R[2009];

int main() {
	// 입력
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &L[i], &R[i]);
	}

	// 영화 선택 시뮬레이션
	// 볼 수 있는 영화 중 종료 시간 최솟값 min_endtime은 일단 1000000(INF로 설정)처럼 나올 수 없는 값으로 설정합니다.
	int answer = 0;
	int current_time = 0; // current_time는 현재 시각(직전에 보았던 영화의 종료 시각)
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < current_time) {
				continue;
			}
			if (min_endtime > R[i]) {
				min_endtime = R[i];
			}
		}
		if (min_endtime == 1000000) {
			break;
		}
		current_time = min_endtime;
		answer += 1;
	}

	// 답 출력
	printf("%d\n", answer);
	return 0;
}
