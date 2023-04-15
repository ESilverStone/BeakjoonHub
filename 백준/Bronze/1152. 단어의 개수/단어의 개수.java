import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		String[] str;
		
		if(sc.hasNext()) {
			
			str = sc.nextLine().split(" ");	
			
			
			if(str[0].equals("")) 	System.out.println(str.length-1);
			else 					System.out.println(str.length);
		}
		else System.out.println(0);	
	}
}