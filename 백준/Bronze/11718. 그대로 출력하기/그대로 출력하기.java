import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		
		while(sc.hasNext()) {
			StringBuilder sb = new StringBuilder();
			
			String[] str = sc.nextLine().split(" ");
			
			for(int i=0; i<str.length; i++) {
				sb.append(str[i]+" ");
				
			}
			
			System.out.println(sb);
			
		}
		
		//System.out.println(sb);
		
		
	}
}