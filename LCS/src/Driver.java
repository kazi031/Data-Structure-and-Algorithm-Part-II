
import java.util.Scanner;
    
public class Driver {
        static char [][] b = new char[50][50];
        static int [][] c = new int[50][50];
        static Scanner sc = new Scanner(System.in);
        static String s1 = sc.nextLine();
        static String s2 = sc.nextLine();
    public static void main(String [] args) {
        
        LCS();
        Print_LCS(s1.length(),s2.length());
        System.out.println("");
    }
    static void LCS(){
        int len1 = s1.length();
        int len2 = s2.length();
        
        for(int i=0;i<=len1;i++){
            c[i][0] =0;
        }
        for(int j = 0;j<=len2;j++){
            c[0][j]=0;
        }
        for(int i=1; i<=len1 ;i++){
            for(int j=1; j<=len2 ; j++){
                if(s1.charAt(i-1)==s2.charAt(j-1))
                {
                    c[i][j] = c[i-1][j-1] + 1;
                    b[i][j] = 'D';
                }
                else if(c[i-1][j] > c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = 'U';
                }
                else {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 'L';
                }
            }
        }
        
        
        
        
        
        
        
        
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                System.out.print(c[i][j]);
                System.out.print(b[i][j]);
                System.out.print("\t");
            }
            System.out.println();
        }
        
    }
    
    
    
    static void Print_LCS(int i,int j){
        if(i==0 || j==0){
            return;
        }
        else if(b[i][j] == 'D'){
            //System.out.print("ok");
            
            Print_LCS(i-1,j-1);
            System.out.print(s1.charAt(i-1));
        }
        else if(b[i][j] == 'L'){
            Print_LCS(i,j-1);
        }
        else if(b[i][j] == 'U'){
            Print_LCS(i-1,j);
        }
    }
}

