import java.util.Scanner;
import java.util.*;

public class Main {
    static int[] A;
    static int answer =0;
    static ArrayList<Integer> vec = new ArrayList<>();
    static void comb(int N, int M, int d, int j){
        if(d == M){
            // Math.max
            int temp = vec.get(0);
            for(int i=1;i<d;i++){
                temp = temp ^ vec.get(i);
                // System.out.print(vec.get(i));
            }
            answer = Math.max(answer, temp);
            // System.out.println();
            return;
        }

        for(int i=j;i<N;i++){
            vec.add(A[i]);
            comb(N,M,d+1, i+1);
            vec.remove(d);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        // Please write your code here.
        comb(n,m,0,0);
        System.out.print(answer);

    }
}