import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		char[] ch = sc.next().toCharArray();
		
		int sum = 0;
		
		for(int i=0; i<ch.length; i++) {
			sum += ch[i] - '0';
		}
		
		System.out.println(sum);
	}
}