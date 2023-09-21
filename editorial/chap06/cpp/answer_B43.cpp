#include <iostream>
using namespace std;
 
int N, M;
int A[200009];
int Incorrect[200009];
 
int main() {
	// 입력
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i];
 
	// 오답 수 구하기
	for (int i = 1; i <= N; i++) Incorrect[i] = 0;
	for (int i = 1; i <= M; i++) Incorrect[A[i]] += 1;
 
	// 답을 출력
	for (int i = 1; i <= N; i++) cout << M - Incorrect[i] << endl;
	return 0;
}
