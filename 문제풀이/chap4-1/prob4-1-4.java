import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		double A = sc.nextDouble();
		double B = sc.nextDouble();
		double H = sc.nextDouble();
		double M = sc.nextDouble();
		
		// 좌표 구하기
		double PI = 3.14159265358979;
		double AngleH = 30.0 * H + 0.5 * M;
		double AngleM = 6.0 * M;
		double Hx = A * Math.cos(AngleH * PI / 180.0);
		double Hy = A * Math.sin(AngleH * PI / 180.0);
		double Mx = B * Math.cos(AngleM * PI / 180.0);
		double My = B * Math.sin(AngleM * PI / 180.0);
		
		// 답 출력
		double d = Math.sqrt((Hx - Mx) * (Hx - Mx) + (Hy - My) * (Hy - My));
		System.out.format("%.12f\n", d);
	}
}