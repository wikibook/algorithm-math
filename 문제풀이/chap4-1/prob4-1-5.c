#include <stdio.h>
#include <stdbool.h>

void swap(long long *x, long long *y) {
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

long long max(long long p1, long long p2) {
	if (p1 < p2) return p2;
	return p1;
}

long long min(long long p1, long long p2) {
	if (p1 < p2) return p1;
	return p2;
}

long long cross(long long ax, long long ay, long long bx, long long by) {
	// # 벡터 (ax, ay)와 (bx, by) 외적의 크기
	return ax * by - ay * bx;
}

int main() {
	// 입력
	long long X1, Y1, X2, Y2, X3, Y3, X4, Y4;
	scanf("%lld%lld", &X1, &Y1); // 점 A의 좌표를 입력
	scanf("%lld%lld", &X2, &Y2); // 점 B의 좌표를 입력
	scanf("%lld%lld", &X3, &Y3); // 점 C의 좌표를 입력
	scanf("%lld%lld", &X4, &Y4); // 점 D의 좌표를 입력
	
	// cross(AB, AC)를 계산
	long long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
	long long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
	long long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
	long long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
	
	// 모두 일직선 위에 있는 경우(코너 케이스)
	// pair 자료형을 사용할 수 없으므로, C++ 코드와 조금 다름
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		if (X1 == X2 && X2 == X3 && X3 == X4) {
			long long a = Y1, b = Y2; if (a > b) swap(&a, &b);
			long long c = Y3, d = Y4; if (c > d) swap(&c, &d);
			if (max(a, c) <= min(b, d)) printf("Yes\n");
			else printf("No\n");
		}
		else {
			long long a = X1, b = X2; if (a > b) swap(&a, &b);
			long long c = X3, d = X4; if (c > d) swap(&c, &d);
			if (max(a, c) <= min(b, d)) printf("Yes\n");
			else printf("No\n");
		}
		return 0;
	}
	
	// 그렇지 않은 경우
	// IsAB: 선분 AB가 점 C, D를 나누는가?
	// IsCD: 선분 CD가 점 A, B를 나누는가?
	bool IsAB = false, IsCD = false;
	if (ans1 >= 0 && ans2 <= 0) IsAB = true;
	if (ans1 <= 0 && ans2 >= 0) IsAB = true;
	if (ans3 >= 0 && ans4 <= 0) IsCD = true;
	if (ans3 <= 0 && ans4 >= 0) IsCD = true;
	
	// 답 출력
	if (IsAB == true && IsCD == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}