#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N,X;
ll Ar[105],dp[1000005];
int solve(int s)
{
    if(s==0)return 0;
    if(s<0)return 1e9;
    if(dp[s]!=-1)return dp[s];
    int ans=1e9;
    for(int i=1;i<=N;i++)
        ans=min(ans,1+solve(s-Ar[i]));
    return dp[s]=ans;
}
int main ()
{
    memset(dp,-1,sizeof dp);
    cin >> N >> X;
    for(int i=1;i<=N;i++)cin >> Ar[i];
    int ans = solve(X);
    if(ans==1e9)cout<<"-1\n";
    else cout<<ans<<endl;
    return 0;
}
