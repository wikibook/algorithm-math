struct State {
 int score; // 잠정 점수
 int X[29]; // 현재 배열 X의 값
 char LastMove; // 마지막 동작('A' 또는 'B'）
 int LastPos; //Beam[i-1][ 어디 ]에서 전이했는가
};
