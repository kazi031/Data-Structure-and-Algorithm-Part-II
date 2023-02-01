public class Driver {
    public static void main(String[] args) {
        int [] P = {2,4,6,4,2};
        MatrixChainOrder(P);
        
        
    }
    static void MatrixChainOrder(int [] P){
        int n = P.length - 1 ;
        int [][] M = new int[n][n];
        int [][] S = new int[n][n];
        for(int i=0;i<n;i++){
            M[i][i] = 0;
        }
        for(int l=2; l<=n ; l++){
            for(int i=0 ; i<(n-l+1) ; i++){
                int j = i + l - 1;
                M[i][j] = 9999;
                for(int k=i ; k<=j-1; k++){
                    int q = M[i][k] + M[k+1][j] + P[i]*P[j]*P[k];
                    if(q < M[i][j]){
                        M[i][j] = q;
                        M[j][i] = k;
                    }
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(M[i][j] + "\t");
            }
            System.out.println("");
        }
    }
}
