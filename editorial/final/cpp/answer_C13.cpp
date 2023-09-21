#include <iostream>
#include <map>
using namespace std;

// a의 b제곱을 m으로 나눈 나머지를 반환하는 함수
long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		int wari = (1 << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m;
		}
		p = (p * p) % m;
	}
	return Answer;
}

// a ÷ b를 m으로 나눈 나머지를 반환하는 함수
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

const long long mod = 1000000007;
long long N, P;
long long A[100009];
map<long long, long long> Count;

int main() {
	// 입력
	cin >> N >> P;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) A[i] %= mod;

	// 카드 j와 i를 선택한다고 가정하자 (j < i)
	// 각 i에 대해 얼마나 많은 j가 조건을 만족하는지 계산한다
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == 0) {
			if (P == 0) Answer += (i - 1);
			else Answer += 0;
		}
		else {
			// A[i]*Goal mod 1000000007 = P를 만족하는 정수 Goal
			long long Goal = Division(P, A[i], mod);
			Answer += Count[Goal];
		}
		Count[A[i]] += 1;
	}
	cout << Answer << endl;
	return 0;
}
