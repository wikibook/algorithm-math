#include <iostream>
using namespace std;

int N, L, K, A[100009];

bool check(int x) {
	int Count = 0, Last_Kireme = 0;// Count는 현 시점에서 몇 번 잘랐는가를 나타낸다
	for (int i = 1; i <= N; i++) {
		if (A[i] - Last_Kireme >= x && L - A[i] >= x) {
			Count += 1;
			Last_Kireme = A[i];
		}
	}
	if (Count >= K) return true;
	return false;
}

int main() {
	// 입력
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 바이너리 서치(left: 현재의 하한/ right: 현재의 상한)
	long long left = 1, right = 1'000'000'000;
	while (left < right) {
		long long mid = (left + right + 1) / 2;
		bool Answer = check(mid);
		if (Answer == false) right = mid - 1; // 답이 전반 부분으로 좁혀진다
		if (Answer == true) left = mid; // 답이 후반 부분으로 좁혀진다
	}

	// 출력
	cout << left << endl;
	return 0;
}
