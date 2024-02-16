package Localrepo;

import java.util.Scanner;

public class spiral_order {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter rows and columns : ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int a[][] = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j] = sc.nextInt();
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("The Spiral Order :");
        int rs=0,re=m-1,cs=0,ce=n-1;
        while (rs<=re && cs<=ce) {
            for(int i=cs;i<=ce;i++){
                System.out.print(a[rs][i]+" ");
            }rs++;
            for(int i=rs;i<=re;i++){
                System.out.print(a[i][ce]+" ");
            }ce--;
            for(int i=ce;i>=cs;i--){
                System.out.print(a[re][i]+" ");
            }re--;
            for(int i=re;i>=rs;i--){
                System.out.print(a[i][cs]+" ");
            }cs++;
        }
        sc.close();
    }
}
