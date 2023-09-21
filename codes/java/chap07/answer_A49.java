import java.util.*;

class Main {
	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		final int N = 20;
		int T = sc.nextInt();
		int[] P = new int[T + 1];
		int[] Q = new int[T + 1];
		int[] R = new int[T + 1];
		for (int i = 1; i <= T; i++) {
			P[i] = sc.nextInt();
			Q[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		
		// 빔 서치(책과 달리 빔 서치 복원은 함수 내에서 수행)
		char[] answer = beamSearch(N, T, P, Q, R);

		// 답 출력
		for (int i = 1; i <= T; i++) {
			System.out.println(answer[i]);
		}
	}

	// 빔 서치를 수행하는 함수
	static char[] beamSearch(int N, int T, int[] P, int[] Q, int[] R) {
		// 2차원 배열 빔을 준비하여 0번째 수의 상태를 설정
		final int WIDTH = 7000; // WIDTH는 빔의 폭
		ArrayList<State>[] beam = new ArrayList[T + 1];
		beam[0] = new ArrayList<>();
		beam[0].add(new State(N));

		// 빔 서치
		for (int i = 1; i <= T; i++) {
			ArrayList<State> candidate = new ArrayList<>();
			for (int j = 0; j < beam[i - 1].size(); j++) {
				// 조작 A인 경우
				State sousaA = new State(beam[i - 1].get(j));
				sousaA.lastMove = 'A';
				sousaA.lastPos = j;
				sousaA.x[P[i]] += 1;
				sousaA.x[Q[i]] += 1;
				sousaA.x[R[i]] += 1;
				for (int k = 1; k <= N; k++) {
					if (sousaA.x[k] == 0) {
						sousaA.score += 1;
					}
				}
				// 조작 B인 경우
				State sousaB = new State(beam[i - 1].get(j));
				sousaB.lastMove = 'B';
				sousaB.lastPos = j;
				sousaB.x[P[i]] -= 1;
				sousaB.x[Q[i]] -= 1;
				sousaB.x[R[i]] -= 1;
				for (int k = 1; k <= N; k++) {
					if (sousaB.x[k] == 0) {
						sousaB.score += 1;
					}
				}
				// 후보에 추가
				candidate.add(sousaA);
				candidate.add(sousaB);
			}
			// 정렬해서 Beam[i]의 결과를 계산한다
			Collections.sort(candidate);
			beam[i] = new ArrayList<State>(candidate.subList(0, Math.min(candidate.size(), WIDTH)));
		}

		// 빔 서치 복원(CurrentPlace는 배열 Beam의 어느 위치를 보고 있는가를 나타낸다)
		char[] answer = new char[T + 1];
		int currentPlace = 0;
		for (int i = T; i >= 1; i--) {
			answer[i] = beam[i].get(currentPlace).lastMove;
			currentPlace = beam[i].get(currentPlace).lastPos;
		}

		return answer;
	}

	// 상태를 나타내는 구조체 State
	static class State implements Comparable<State> {
		int score;     // 잠정 점수
		int[] x;       // 현재 배열 X의 값
		char lastMove; // 마지막 동작('A' 또는 'B'）
		int lastPos;   // Beam[i-1][어디]에서 전환한 내용
		// 상태 초기화
		public State(int N) {
			score = 0;
			x = new int[N + 1];
			lastMove = '?';
			lastPos = -1;
		}
		// 생성자
		public State(State s) {
			score = s.score;
			x = s.x.clone();
			lastMove = s.lastMove;
			lastPos = s.lastPos;
		}
		@Override public int compareTo(State s) {
			return s.score - score; // 정렬 시 self.score > s.score일 때 self가 s보다 앞에 오도록 함
		}
	}
}