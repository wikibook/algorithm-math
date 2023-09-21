#include <iostream>
using namespace std;

long long N, K;
long long A[100009];

// 답이 x 이하인지 판정하고 Yes라면 true, No라면 false를 반환한다
bool check(long long x) {
	long long sum = 0;
	for (int i = 1; i <= N; i++) sum += x / A[i]; //'x ÷ A[i]'의 소수점 이하를 버린다
	if (sum >= K) return true;
	return false;
}

int main() {
	// 입력
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 바이너리 서치
	// Left는 탐색 범위의 왼쪽 끝, Right는 탐색 범위의 오른쪽 끝을 나타낸다
	long long Left = 1, Right = 1'000'000'000;
	while (Left < Right) {
		long long Mid = (Left + Right) / 2;
		bool Answer = check(Mid);
		if (Answer == false) Left = Mid + 1; // 답이 Mid+1 이상임을 알 수 있다
		if (Answer == true) Right = Mid; // 답이 Mid 이하임을 알 수 있다
	}

	// 출력(이때, Left=Right가 된다)
	cout << Left << endl;
	return 0;
}
