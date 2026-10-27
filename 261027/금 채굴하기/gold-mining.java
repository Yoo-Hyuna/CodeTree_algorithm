import java.util.Scanner;
import java.*;
public class Main {
    static int n;
    public static int[][] grid;// = new int[n][n];
    
    static int check(int k, int i, int j){
        int count =0;
        for(int r=0; r<=k; r++){        // 현재 행 & 위로
            int tr = i-r;
            if(tr>=0){
                if(grid[tr][j] ==1) count++;
            }else{
                break;
            }
            
            for(int c=1; c<=k-r; c++){
                if(j+c >= n) break;

                if(grid[tr][j+c] ==1) count++;
            }

            for(int c=1; c<=k-r; c++){
                if(j-c < 0) break;

                if(grid[tr][j-c] ==1) count++;
            }
        }

        for(int r=1; r<=k; r++){        // 아래로
            int tr = i+r;
            if(tr<n){
                if(grid[tr][j] ==1) count++;
            }else{
                break;
            }
            
            for(int c=1; c<=k-r; c++){
                if(j+c >= n) break;

                if(grid[tr][j+c] ==1) count++;
            }

            for(int c=1; c<=k-r; c++){
                if(j-c < 0) break;

                if(grid[tr][j-c] ==1) count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
        n = sc.nextInt();
        int m = sc.nextInt();
        int cnt = 0;
        // int[][] 
        grid = new int[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                grid[i][j] = sc.nextInt();
                if(grid[i][j] == 1) cnt++;
            }
        }
        // Please write your code here.
        int k=0;
        int answer =0;
        while(true){
            if(cnt*m < k*k+(k+1)*(k+1)) break;

            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    int temp = check(k, i, j);
                    if(temp*m >= k*k+(k+1)*(k+1)) answer = Math.max(answer, temp);
                    // if(temp == 6) System.out.println("위치: " +i+ ", " + j + ", " + k);
                    // answer = Math.max(answer, temp);
                }
            }
            k++;
        }        
        System.out.print(answer);
    }
}