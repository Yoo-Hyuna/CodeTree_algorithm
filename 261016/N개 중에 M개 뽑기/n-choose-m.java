import java.util.Scanner;
import java.util.*;

public class Main {
    static ArrayList<Integer> list = new ArrayList<>();

    static void comb(int N, int M, int d, int j){
        if(d == M){
            for(int i=0;i<M;i++){
                System.out.print(list.get(i) + " ");
            }
            System.out.println();
            return;
        }
        
        for(int i=j; i<=N; i++){
            list.add(i);
            comb(N,M,d+1, i+1);
            list.remove(d);
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        // Please write your code here.
        comb(n,m,0, 1);

    }
}