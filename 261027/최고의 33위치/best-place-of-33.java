import java.util.Scanner;
import java.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.
        int answer =0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=n-3;j++){
                int temp =0;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(grid[i+k][j+l] == 1) temp++;
                    }
                }
                answer = Math.max(answer, temp);
            }
        }
        System.out.print(answer);
    }
}