#include <iostream>
#include <algorithm>
using namespace std;
 
// Movie 자료형
struct Movie {
	int l, r;
};
 
bool operator<(const Movie &a1, const Movie &a2) {
	if (a1.r < a2.r) return true;
	if (a1.r > a2.r) return false;
	if (a1.l < a2.l) return true;
	return false;
}
 
int N;
Movie A[300009];
int CurrentTime = 0; // 현재 시각(마지막에 선택한 영화의 종료 시각)
int Answer = 0; // 현재까지 본 영화 수
 
int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i].l >> A[i].r;
	
	// 정렬
	sort(A + 1, A + N + 1);
	
	// 종료 시각이 가장 빠른 것 선택하기를 반복함
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= A[i].l) {
			CurrentTime = A[i].r;
			Answer += 1;
		}
	}
	
	// 출력
	cout << Answer << endl;
	return 0;
}