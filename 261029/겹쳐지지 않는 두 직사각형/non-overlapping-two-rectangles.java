import java.util.Scanner;
import java.*;

public class Main {
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
        int answer =-25001;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                //크기 잡기
                for(int tn=1; tn<=n-i; tn++){
                    for(int tm=1; tm<=m-j; tm++){
                        // 영역 합
                        int sum = 0;
                        boolean[][] visited = new boolean[n][m];
                        for(int k=0; k<tn; k++){
                            for(int l=0; l<tm; l++){
                                sum += grid[i+k][j+l];
                                visited[i+k][j+l] = true;
                            }
                        }
                        if(tn == 1 && tm == 1){}
                        else{
                            answer = Math.max(sum, answer);
                        }


                        // 남은 공간에서 마지막 직사각형 찾기
                        for(int pi=0; pi<n; pi++){
                            for(int pj=0; pj<m; pj++){

                                //크기 잡기
                                for(int pn=1; pn<=n-pi; pn++){
                                    for(int pm=1; pm<=m-pj; pm++){
                                        // 영역 합
                                        int psum = 0;
                                        boolean cant = false;

                                        for(int k=0; k<pn; k++){
                                            for(int l=0; l<pm; l++){
                                                if(visited[pi+k][pj+l] == true){
                                                    cant = true;
                                                    break;
                                                }else psum += grid[pi+k][pj+l];
                                            }
                                            if(cant == true) break;
                                        }

                                        if(cant == false){
                                            answer = Math.max(sum + psum, answer);
                                        }
                                    
                                    }
                                }

                            }
                        }
                    
                    }
                }

            }
        }

        System.out.print(answer);
    }
}