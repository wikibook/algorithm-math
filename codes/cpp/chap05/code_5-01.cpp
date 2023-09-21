// x가 소수일 때 true, 소수가 아닐 때 false를 반환한다
bool isPrime(int x) {
	for (int i = 2; i <= x - 1; i++) {
		if (x % i == 0) return false;
	}
	return true;
}
