import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static int[] vi = {1,0,-1,0};
	public static int[] vj = {0,-1,0,1};
	
	public static int N;
	public static int M;
	public static int cnt = 0;
	public static int cnt2 = 0;
	
	public static int[][] arr;
	public static int[][] visit;
	
	public static void bfs(int i, int j) {
		Queue<int[]> que = new LinkedList<>();
		
		que.add(new int[] {i,j});
		visit[i][j] = 1;
		
		while(!que.isEmpty()) {
			cnt++;
			int[] get = que.poll();
			int getI = get[0];
			int getJ = get[1];
			
			
			for(int v=0; v<4; v++) {
				int setI = getI + vi[v];
				int setJ = getJ + vj[v];
							
				if(setI < 0 || setJ < 0 || setI >= N || setJ >= M) continue;
				
				if(visit[setI][setJ] == 1 || arr[setI][setJ] == 0) continue;
				
				que.add(new int[] {setI,setJ});
				arr[setI][setJ] = arr[getI][getJ] + 1;
				visit[setI][setJ] = 1;			
			}	
		}	
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		
		arr = new int[N][M];
		visit = new int[N][M];
		
		// 입력
		for(int i=0; i<N; i++) {
			char[] ch = sc.next().toCharArray();
			
			for(int j=0; j<M; j++) {
				arr[i][j] = ch[j] - '0';
			}
		}
		
		bfs(0,0);
		
		System.out.println(arr[N-1][M-1]);	
	}
}