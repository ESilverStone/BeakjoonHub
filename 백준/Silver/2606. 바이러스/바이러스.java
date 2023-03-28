import java.util.Scanner;

public class Main {
	
	public static boolean[][] cnnt;
	public static boolean[] visit;
	public static int N;
	
	
	public static void dfs(int idx) {
		
		visit[idx] = true;
		
		for(int i=0; i<N; i++) {
			if(!visit[i] && cnnt[i][idx]) {
				visit[i] = true;
				dfs(i);
			}
		}
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		int M = sc.nextInt();
		
		cnnt = new boolean[N][N];
		visit = new boolean[N];
		
		for(int i=0; i<M; i++) {
			
			int m1 = sc.nextInt()-1;
			int m2 = sc.nextInt()-1;
			
			cnnt[m1][m2] = cnnt[m2][m1] = true;
		}
		
		dfs(0);
		
		int cnt = 0;
		for(boolean i: visit) {
			if(i) cnt++;
		}
		System.out.println(cnt-1);
	}
}