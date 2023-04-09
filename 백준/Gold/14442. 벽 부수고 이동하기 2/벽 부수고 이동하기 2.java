import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	// 현재 지점을 담는 클래스 + 오함마 사용했는지 체크
	static class point {
		int i;
		int j;
		int cnt;
		int use;
		
		public point(int i, int j, int cnt, int use) {
			this.i = i;
			this.j = j;
			this.cnt = cnt;
			this.use = use;
		}	
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][M];
		boolean [][][] visit = new boolean[N][M][K+1];
		
		for(int i=0; i<N; i++) {
			String[] str = br.readLine().split("");
			
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(str[j]);
				
			}
		}
		
		int[] vi = {1,-1,0,0};
		int[] vj = {0,0,1,-1};
		
	
		Queue<point> que = new LinkedList<>();
		
		que.add(new point(0,0,1,0));
		
		
		int cnt = -1;
		boolean poss = false;
		
		while(!que.isEmpty()) {
			
			point loc = que.poll();
		                
			if(loc.i == N-1 && loc.j == M-1) { 
				cnt = loc.cnt;
				poss = true;
				break;
			}
			
			for(int v=0; v<4; v++) {
				
				int curI = loc.i + vi[v];
				int curJ = loc.j + vj[v];
				int curC = loc.cnt;
				int curU = loc.use;
	
				// 배열 밖
				if(curI < 0 || curJ < 0 || curI >= N || curJ >= M) continue;
					
				if(visit[curI][curJ][loc.use]) continue;
				visit[curI][curJ][loc.use] = true;
				
				// 1이면 망치를 사용해서 이동한다. 사용횟수 k보다 적어야함
				if(map[curI][curJ] == 1 && curU < K) {
					que.add(new point(curI, curJ, curC+1, curU+1));
				}
				// 0인 구역은 그냥 이동한다.
				else if(map[curI][curJ] == 0) {
					que.add(new point(curI, curJ, curC+1, curU));
					
				}
			}
		}
		
		if(poss) 
			System.out.println(cnt);
		else
			System.out.println(-1);
	}
}