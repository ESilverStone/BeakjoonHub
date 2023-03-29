import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long a = sc.nextInt();
		long b = sc.nextInt();
		long c = sc.nextInt();
		
		a %= c;
		
		long result = 1;

		while(b>0) {
			
			if((b & 1) == 1) {
				result *= a;
				result %= c;
			}
			
			b >>= 1;
			a *= a;
			a %= c;
		}
		
		System.out.println(result);
	}
}