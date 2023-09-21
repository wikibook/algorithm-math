void update(int pos, int x) { // 셀 i에 쓰여진 정수를 dat[i]로 나타낸다
	pos = pos + siz - 1;
	dat[pos] = x;
	while (pos >= 2) {
		pos /= 2;
		dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
	}
}
