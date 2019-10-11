#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;
ll N,A[25][25],dp[1<<22];
bool Check(int ith,ll x)
{
    return x&(1<<ith);
}
ll Set(int ith,ll x)
{
    return x|(1<<ith);
}
ll solve(int idx,ll mask)
{
    if(__builtin_popcount(mask)==N)return 1;
    if(idx>=N)return 0;
    if(dp[mask]!=-1)return dp[mask];
    ll res=0;
    for(int j=0;j<N;j++){
        if(A[idx][j])
        {
            if(Check(j,mask)==0)
            {
                res+=solve(idx+1,Set(j,mask))%MOD;
            }
        }
    }
    return dp[mask]=res%MOD;
}
int main  ()
{
    memset(dp,-1,sizeof dp);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)cin>>A[i][j];
    }
    cout<<solve(0,0);
    return 0;
}
