G[pos][i].cap -= flow; // 에지의 용량을 flow 감소시킨다
G[G[pos][i].to][G[pos][i].rev].cap += flow; // 역에지의 용량을 flow 증가시킨다
