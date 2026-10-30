import java.util.Scanner;
import java.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = sc.nextInt();
        // Please write your code here.
        int answer = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                for(int r=1;r<=n-i;r++){
                    for(int c=1; c<=m-j; c++){
                        boolean cant = false;
                        for(int k=0;k<r;k++){
                            for(int l=0;l<c;l++){
                                if(grid[i+k][j+l] <= 0){
                                    cant = true;
                                    break;
                                }
                            }
                            if(cant == true) break;
                        }
                        if(cant==false){
                            answer = Math.max(answer, r*c);
                        }
                    }
                }

            }
        }
        System.out.print(answer);

    }
}