#include <stdio.h>
#include <stdbool.h>

int N;
double A[509], B[509], C[509];

bool check(double x, double y) {
	for (int i = 1; i <= N; i++) {
		if (A[i] * x + B[i] * y > C[i]) return false;
	}
	return true;
}

// a1과 a2 중에 큰 값을 리턴하는 함수
double max(double a1, double a2) {
	if (a1 < a2) {
		return a2;
	}
	return a1;
}

int main() {
	// 입력
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lf%lf%lf", &A[i], &B[i], &C[i]);
	
	// 교점 전체 탐색
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// 교점을 갖지 않는 경우
			if (A[i] * B[j] == A[j] * B[i]) continue;
			
			// i번째 직선(조건식의 경계)와 j번째 직선(조건식의 경계) 사이의 교점을 구함
			double px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
			double py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
			bool ret = check(px, py);
			if (ret == true) {
				Answer = max(Answer, px + py);
			}
		}
	}
	
	// 답 출력
	printf("%.12lf\n", Answer);
	return 0;
}