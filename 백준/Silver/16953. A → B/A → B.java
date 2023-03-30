import java.util.Scanner;

public class Main {
	
	public static long b;
	public static int minCnt;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long a = sc.nextInt();
		b = sc.nextInt();
		
		minCnt = Integer.MAX_VALUE;
		
		bfs(a,1);
		if(minCnt == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(minCnt);
	}

	public static void bfs(long a, int cnt) {
		
		//System.out.println(a +" "+ "cnt:" + cnt);
		
		if(a > b) return;
		else if(a == b) {
			if(minCnt > cnt) {
				minCnt = cnt;
			}
		}
		
		if(minCnt <= cnt) return;
		
		
		
		// append 1
		bfs(a*10+1, cnt+1);
		
		
		// double
		bfs(a*2, cnt+1);
			
	}
}