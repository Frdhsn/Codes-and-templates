#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
int N,A[MAX],B[MAX],C[MAX],dp[MAX][3];
int solve(int idx,int pr)
{
    if(idx>N)return 0;
    if(dp[idx][pr]!=-1)return dp[idx][pr];
    int res=0;
    for(int i=1;i<=3;i++){
        if(i==pr)continue;
        int val=0;
        if(i==1)val=A[idx];
        if(i==2)val=B[idx];
        if(i==3)val=C[idx];
        res = max(res,solve(idx+1,i)+val);
    }
    return dp[idx][pr]=res;
}
int  main ()
{
    memset(dp,-1,sizeof dp);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    cout<<solve(1,0)<<endl;
    return 0;
}


