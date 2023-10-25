import java.util.*;

class Code_2_01_4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 입력 부분
		String answer = ""; // String은 문자열 자료형
		while (N >= 1) {
			// N % 2는 N를 2로 나눈 나머지(예: N = 13의 경우 1)
			// N / 2는 N를 2로 나눈 몫(예:N = 13의 경우 6)
			if (N % 2 == 0) {
				answer = "0" + answer;
			}
			if (N % 2 == 1) {
				answer = "1" + answer;
			}
			N = N / 2;
		}
		System.out.println(answer); // 출력 부분
	}
};
