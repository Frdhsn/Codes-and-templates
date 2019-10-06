#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e3+5,MOD=1e9+7;
int dp[MAX][MAX] , n;
string S[MAX];
ll solve(int i,int j){
    if(S[i][j]=='*')return 0LL;
    if(i==n-1&&j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int res=0;
    if(i+1<n)res=solve(i+1,j)%MOD;
    if(j+1<n)res=res + solve(i,j+1)%MOD;
    res%=MOD;
    return dp[i][j]=res;
}
int main() {
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)cin>>S[i];
	cout<<solve(0,0)<<endl;
	return 0;
}
