import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static List<Integer> listI;
    public static List<Integer> listJ;

    public static int[][] arr;
    public static boolean[][] domino;
    public static int cnt;

    // 아래, 오른쪽 벡터
    static int[] vI = {1, 0};
    static int[] vJ = {0, 1};

    public static boolean sudoku(int idx,int[][] arr) {
    	    	
        // 탈출~
        if(idx == listI.size()) return true;

        int setI = listI.get(idx);
        int setJ = listJ.get(idx);

        // 아직 공백인 경우
        if(arr[setI][setJ] == 0) {

            for(int v=0; v<2; v++) {

                int othI = setI + vI[v];
                int othJ = setJ + vJ[v];

                // 범위를 넘었을 경우
                if(othI < 0 || othI >= 9 || othJ < 0 || othJ >= 9) continue;

                // 거기에 뭔가가 있는 경우
                if(arr[othI][othJ] != 0) continue;

                for(int i=1; i<=9; i++) {            // 내 번호
                    for(int j=1; j<=9; j++) {        // 깐부 번호

                        // i랑 j가 같은 도미노는 존재하지 않음. 
                        // 이미 거쳐간 도미노면 아웃
                        if(i==j || domino[i][j]) continue;

                        // 깐부도 같이 체크
                        if(check(setI, setJ, i,arr) && check(othI, othJ, j,arr)) {

                            arr[setI][setJ] = i;
                            arr[othI][othJ] = j;

                            domino[i][j] = domino[j][i] = true;

                            if(sudoku(idx+1,arr)) return true;

                            // 초기화
                            arr[setI][setJ] = 0;
                            arr[othI][othJ] = 0;

                            domino[i][j] = domino[j][i] = false;
                        }
                    }
                   
                } 
            }
        } else return(sudoku(idx+1, arr));

        return false;
    }

    // 중복된 숫자가 있는지 체크하는 그거
    public static boolean check(int row, int col, int val, int[][] arr) {
        // 가로 검사
        for(int i=0; i<9; i++) {
            if(arr[row][i] == val) return false;
        }

        // 세로 검사
        for(int i=0; i<9; i++) {
            if(arr[i][col] == val) return false;
        }

        int setRow = (row / 3) * 3;
        int setCol = (col / 3) * 3;

        // 9칸 체크
        for(int i=setRow; i<setRow+3; i++) {
            for(int j=setCol; j<setCol+3; j++) {
                if(arr[i][j] == val) {
                    return false;
                }
            }
        }
        // 중복되는 숫자가 없는 경우
        return true;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        StringBuilder sb = new StringBuilder();
        
        int t = 1;
        while(true) {

            int N = Integer.parseInt(br.readLine());

            if(N==0) break;
            
            listI = new ArrayList<Integer>();
            listJ = new ArrayList<Integer>();
            
            // 스도쿠가 담길 보드
            // 사용된 도미노 체크 보드
            int[][] arr = new int[9][9];
            domino = new boolean[10][10];

            for (int i = 0; i < 9; i++) {
                Arrays.fill(arr[i], 0);
            }
            
            for (boolean[] row : domino) {
                Arrays.fill(row, false);
            }

            // 입력1
            for(int i=0; i<N; i++) {

                st = new StringTokenizer(br.readLine());

                // 첫 번째 숫자
                int n1 = Integer.parseInt(st.nextToken());

                // 첫 번째 숫자의 위치
                char[] ch1 = st.nextToken().toCharArray();

                arr[ch1[0]-'A'][ch1[1]-'1'] = n1;


                // 두 번째 숫자
                int n2 = Integer.parseInt(st.nextToken());

                // 두 번째 숫자의 위치
                char[] ch2 = st.nextToken().toCharArray();

                arr[ch2[0]-'A'][ch2[1]-'1'] = n2;

                domino[n1][n2] = domino[n2][n1] = true;    // 사용된 도미노 체크 
                
            }
                
            // 입력 2
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<9; i++) {
            	char[] ch = st.nextToken().toCharArray();
            	arr[ch[0]-'A'][ch[1]-'1'] = i+1;
            }

            
            // 0위치 저장
        	for(int i=0; i<9; i++) {
        		for(int j=0; j<9; j++) {
        		
        			if(arr[i][j] == 0) {
        				listI.add(i);
        				listJ.add(j);
        				cnt++;
        			}
        		}
        	}
            
            sb.append("Puzzle ").append(t).append("\n");
            
            sudoku(0,arr);
            
            for(int i=0; i<9; i++) {
            	for(int j=0; j<9; j++) {
            		sb.append(arr[i][j]);
            	}
            	sb.append("\n");
            }
            t++;    
        }
        System.out.println(sb);
        br.close();
    }
}