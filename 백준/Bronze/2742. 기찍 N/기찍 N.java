import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		StringBuilder sb = new StringBuilder();
		
		for(int i=n; i>=1; i--) {
			sb.append(i+"\n");
		}
		
		System.out.println(sb);
		
		
	}
}