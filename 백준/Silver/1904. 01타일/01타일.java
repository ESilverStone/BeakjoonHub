import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static int[] dp = new int[1000001];
	
	public static int cal(int n) {
		
		if(dp[n] == -1) {
			dp[n] = (cal(n-1) + cal(n-2)) % 15746;
		}
		
		return dp[n];
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		Arrays.fill(dp, -1);
		
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		
		
		
		System.out.println(cal(n));
	}
}