public class Driver {
    static int [] A = {0,2,30,35,15,10,8,26,31};
    public static void main(String[] args) {
        MergeSort(1,8);
    }
    static void MergeSort(int p,int r){
        if(p<r){
            int q = (p+r)/2;
//            for(int i=p;i<=q;i++){
//                System.out.print(A[i]+" ");
//            }
//            System.out.println("");
            MergeSort(p,q);
//            for(int i=q+1;i<=r;i++){
//                System.out.print(A[i]+" ");
//            }
//            System.out.println("");
            MergeSort(q+1,r);
            System.out.println("Merge : ");
            Merge(p,q,r);
            System.out.println("After Merge");
            for(int i = 1 ;i<A.length;i++){
                System.out.print(A[i]+" ");
            }
            System.out.println("");
        }
    }
    static void Merge(int p,int q,int r){
        //int n1 = q-p+1+1+1;
        int n1 = q-p+1;
        //int n2 = r-q+1+1;
        int n2 = r-q;
        int [] L = new int[n1+2];
        int [] R = new int[n2+2];
        for(int i = 1;i<=n1;i++){
            L[i] = A[p+i-1];
        }
        L[n1+1] = 9999;
        
        for(int j = 1;j<=n2;j++){
            R[j] = A[q+j];
        }
        R[n2+1] = 9999;

        
        int i = 1;
        int j = 1;
        
        for(int k = p;k<=r;k++){
            if(L[i]<R[j]){
                A[k] = L[i];
                i = i + 1;
            }
            else{
                A[k] = R[j];
                j = j + 1;
            }
        }
    }
}
