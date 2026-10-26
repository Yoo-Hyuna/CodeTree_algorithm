import java.util.Scanner;
import java.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        
        // Please write your code here.
        int answer =0;
        for (int i = 0; i < n; i++){
            int cnt =1;
            int before =0;
            for (int j = 0; j < n; j++){
                if(before == 0) before = grid[i][j];
                else{
                    if(grid[i][j] == before) cnt++;
                    else{
                        cnt=1;
                        before  = grid[i][j];
                    }
                }
                

                if(cnt >= m){
                    answer++;
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++){
            int cnt =1;
            int before =0;
            for (int i = 0; i < n; i++){
                if(before == 0) before = grid[i][j];
                else{
                    if(grid[i][j] == before) cnt++;
                    else{
                        cnt=1;
                        before  = grid[i][j];
                    }
                }
                    
                if(cnt >= m){
                    answer++;
                    break;
                }
            }
        }
        System.out.print(answer);
    }
}