#include <iostream>
using namespace std;

long long cross(long long ax, long long ay, long long bx, long long by) {
	// # 벡터 (ax, ay)와 (bx, by) 외적의 크기
	return ax * by - ay * bx;
}

int main() {
	// 입력
	long long X1, Y1, X2, Y2, X3, Y3, X4, Y4;
	cin >> X1 >> Y1; // 점 A의 좌표를 입력
	cin >> X2 >> Y2; // 점 B의 좌표를 입력
	cin >> X3 >> Y3; // 점 C의 좌표를 입력
	cin >> X4 >> Y4; // 점 D의 좌표를 입력
	
	// cross(AB, AC)를 계산
	long long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
	long long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
	long long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
	long long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
	
	// 모두 일직선 위에 있는 경우(코너 케이스)
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		// A, B, C, D를 숫자 값(정확하게는 pair 자료형)으로 변환
		// 적당하네 swap해서 A<B, C<D가 되게 만듦
		// 이렇게 하면 구간 중첩 판정(절말문제 2.5.6)처럼 풀 수 있음
		pair<long long, long long> A = make_pair(X1, Y1);
		pair<long long, long long> B = make_pair(X2, Y2);
		pair<long long, long long> C = make_pair(X3, Y3);
		pair<long long, long long> D = make_pair(X4, Y4);
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		if (max(A, C) <= min(B, D)) cout << "Yes" << endl;
		else cout << "No" << endl;
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
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}