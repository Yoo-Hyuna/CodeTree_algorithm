import java.util.Scanner;
import java.*;

public class Main {
    static class pos{
        int r;
        int c;
        public pos(int r, int c){
            this.r =r;
            this.c =c;
        }
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.
        pos[][] b1 = {
            {
                new pos(0,0),
                new pos(1,0),
                new pos(1,1)
            },
            {
                new pos(0,0),
                new pos(0,1),
                new pos(1,0)
            },
            {
                new pos(0,0),
                new pos(0,1),
                new pos(1,1)
            },
            {
                new pos(0,1),
                new pos(1,0),
                new pos(1,1)
            }
        };
        pos[][] b2 = {
            {
                new pos(0,0),
                new pos(0,1),
                new pos(0,2)
            },
            {
                new pos(0,0),
                new pos(1,0),
                new pos(2,0)
            }
        };

        int answer =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int cnt =0;
                    boolean can = true;

                    for(int l=0;l<3;l++){
                        int tr = b1[k][l].r+i;
                        int tc = b1[k][l].c+j;
                        if(tr<0 || tc<0 || tr>=n||tc>=m){
                            can = false;
                            break;
                        }else{
                            cnt += grid[tr][tc];
                        }
                    }
                    if(can){
                        answer = Math.max(cnt, answer);
                    }
                }

                for(int k=0;k<2;k++){
                    int cnt =0;
                    boolean can = true;
                    for(int l=0;l<3;l++){
                        int tr = b2[k][l].r+i;
                        int tc = b2[k][l].c+j;
                        if(tr<0 || tc<0 || tr>=n||tc>=m){
                            can = false;
                            break;
                        }else{
                            cnt += grid[tr][tc];
                        }
                    }
                    if(can){
                        answer = Math.max(cnt, answer);
                    }
                }
            }
        }
        System.out.print(answer);
    }
}