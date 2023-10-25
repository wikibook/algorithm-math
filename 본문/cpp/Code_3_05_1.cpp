#include <iostream>
using namespace std;

int main() {
	int N = 10000; // N은 시행 횟수(적절하게 변경해서 사용해 주세요)
	int M = 0;
	for (int i = 1; i <= N; i++) {
		double px = rand() / (double)RAND_MAX; // 0 이상 1 이하의 랜덤한 숫자 생성
		double py = rand() / (double)RAND_MAX; // 0 이상 1 이하의 랜덤한 숫자 생성
		// 원점에서의 거리 sqrt(px * px + py * py)가
		// 1 이하라면 원 안에 있는 것이므로, 조건을 "px * px + py * py <= 1"로 설정
		if (px * px + py * py <= 1.0) M += 1;
	}
	printf("%.12lf\n", 4.0 * M / N);
	return 0;
}