#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e3 + 10;
const int MOD=1e9 + 7;
int n,m,dp[MAX][MAX];
string S[MAX];
bool vis[MAX];
bool valid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
int dfs(int x,int y)
{
    if(valid(x,y)==0 || S[x][y]=='#')return 0;
    if(x==n-1&&y==m-1)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    int ans=0;
    ans+=dfs(x+1,y)%MOD;
    ans+=dfs(x,y+1)%MOD;
    return dp[x][y]=ans%MOD;
}
int main ()
{
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    for(int i=0;i<n;i++)cin>>S[i];

    cout<<dfs(0,0);
    return 0;
}

