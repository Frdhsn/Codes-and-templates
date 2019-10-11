#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
int N,A[MAX],dp[MAX];
int solve(int idx)
{
    if(idx==N)return 0;
    if(idx>N)return 1e9;
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx]=min(abs(A[idx+1]-A[idx])+solve(idx+1),abs(A[idx+2]-A[idx])+solve(idx+2));
}
int  main ()
{
    memset(dp,-1,sizeof dp);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    cout<<solve(1)<<endl;
    return 0;
}
