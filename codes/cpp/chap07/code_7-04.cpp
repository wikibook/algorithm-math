// sort 함수의 순서를 결정한다(점수가 높은 쪽이 '크다'고 한다)
bool operator>(const State& a1, const State& a2) {
	if (a1.score > a2.score) return true;
	else return false;
}
