#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+5,MOD=1e9+7;
ll dp[MAX][101] , n , m, A[MAX];
int solve(int idx,ll prev){
    if(idx>=n)return 1LL;
    if(A[idx]&&abs(prev-A[idx])>1)return 0LL;
    if(dp[idx][prev]!=-1)return dp[idx][prev];
    ll res = 0;
    if(idx==0){
            if(A[idx]==0) for(int i=1;i<=m;i++)res+=solve(idx+1,i)%MOD;
            else res=solve(idx+1,A[idx])%MOD;
    }
    else{
    if(A[idx]==0){
            for(int i=max(1LL,prev-1);i<=min(m,prev+1);i++)res+=solve(idx+1,i)%MOD;
    }
    else res = solve(idx+1 , A[idx])%MOD;}
    return dp[idx][prev] = res%MOD;
}
int main() {
    memset(dp,-1,sizeof dp);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>A[i];
 
    cout<<solve( 0 , A[0])<<endl;
	
