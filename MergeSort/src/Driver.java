public class Driver {
    static int [] A = {0,2,30,15,12,1,25};
    public static void main(String[] args) {
        MergeSort(1,6);
    }
    static void MergeSort(int p,int r){
        if(p<r){
            int q = (p+r)/2;
            for(int i=p;i<=q;i++){
                System.out.print(A[i]+"\t");
            }
            System.out.println("");
            MergeSort(p,q);
            for(int i=q+1;i<=r;i++){
                System.out.print(A[i]+"\t");
            }
            System.out.println("");
            MergeSort(q+1,r);
        }
    }
    static void Merge(int p,int q,int r){
        int n1 = q-p+1;
        int n2 = r-q-1+1;
        int [] L = new int[n1+1];
        int [] R = new int[n2+1];
        for(int i = p;i<=q;i++){
            L[i] = A[i];
        }
        for(int j= q+1;j<=r;j++){
            R[j] = A[j];
        }
        L[n1+1] = 9999;
        R[n2+1] = 9999;
        int i = 1;
        int j = 1;
        for(int k = p ; k<=r ;k++){
            if(L[i]<R[i]){
                A[k] = L[i];
                i++;
            }
            else{
                A[k] = R[j];
                j++;
            }
        }
    }
}
