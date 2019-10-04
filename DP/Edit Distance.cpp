int ED(int i,int j){
    if(i==-1)return j+1;
    if(j==-1)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    int ret=1e9;
    if(A[i]==B[j]) ret = ED(i-1,j-1);
    else ret=1 + min( ED(i-1, j) , // remove
                 min(ED(i, j-1) , //insert
                 ED(i-1, j-1) // replace
                 ));
    return dp[i][j]=ret;
}
// call with : ED( n-1 , m-1 );
