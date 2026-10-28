import java.util.Scanner;
import java.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        // Please write your code here.
        int answer =0;
        for (int i = 2; i < n; i++){
            for (int j = 1; j < n-1; j++){
                // System.out.println("update i: " + i + ", j: " + j);
                for(int l=1; l<=i; l++){
                    int dr = i-l, dc = j-l;
                    // System.out.println("update left size: "+ l);
                    if(dr < 0 || dc < 0) break;

                    for(int r=1; r<=i; r++){
                        int br = i-r, bc = j+r;
                        int cr = dr-r, cc = dc+r;
                        if(br >=0 && bc <n && cr>=0 && cc <n ){
                            // System.out.println(
                            //     "left: " + l + ", right: " + r +
                            //     ", i: " + i + ", j: " + j +
                            //     ", bi: " + br + ", bj: " + bc +
                            //     ", ci: " + cr + ", cj: " + cc +
                            //     ", di: " + dr + ", dj: " + dc
                            // );

                            int cnt =0;
                            for(int p=0;p<=r;p++){
                                cnt += grid[i-p][j+p];  //1
                                cnt += grid[dr-p][dc+p]; //3
                            }
                            for(int p=1;p<l;p++){
                                cnt += grid[i-p][j-p];  //4
                                cnt += grid[br-p][bc-p]; // 2
                            }
                            answer = Math.max(answer, cnt);
                        }else break;
                    }
                }
            }
        }

        System.out.print(answer);

        
        
    }
}