import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int[][] map;
	static boolean[][] visit;
	static int N;
	static int cnt;
	
	// 벡터
	static int[] vi = {1,0,-1,0};
	static int[] vj = {0,-1,0,1};
	
	
	public static void trl(int i, int j) {
		// 0인 경우는 그냥 나가기
		if(map[i][j] == 0 || visit[i][j]) return;
		
		cnt++;
		
		// 방문 체크
		visit[i][j] = true;
		
		for(int v=0; v<4; v++) {
			
			int setI = i + vi[v];
			int setJ = j + vj[v];
			
			if(setI < 0 || setJ < 0 || setI >= N || setJ >= N) continue;
			
			// 해당 값이 0이거나 이미 방문한 경우
			if(map[setI][setJ] == 0 || visit[setI][setJ]) continue;
			trl(setI, setJ);		
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		map = new int[N][N];
		visit = new boolean[N][N];
		List<Integer> list = new ArrayList<Integer>();
		
		for(int i=0; i<N; i++) {
			char[] ch = sc.next().toCharArray();
			for(int j=0; j<N; j++) {
				map[i][j] = ch[j] - '0';	
			}
		}
		
		for(int i=0; i<N; i++) {
		
			for(int j=0; j<N; j++) {
				cnt = 0;
				trl(i, j);
				if(cnt != 0) list.add(cnt);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append(list.size()).append("\n");
		
		Collections.sort(list);
		for(int i=0; i<list.size(); i++) {
			sb.append(list.get(i)).append("\n");
		}
		
		System.out.println(sb);
	}
}