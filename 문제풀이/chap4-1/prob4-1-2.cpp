#include <iostream>
#include <cmath>
using namespace std;

int N;
double x[2009], y[2009];
double Answer = 1000000000.0; // 굉장히 큰 값으로 초기화

int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
	
	// 전체 탐색
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// dist는 i번째 점과 j번째 점 사이의 거리
			double dist = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
			Answer = min(Answer, dist);
		}
	}
	
	// 답 출력
	printf("%.12lf\n", Answer);
	return 0;
}