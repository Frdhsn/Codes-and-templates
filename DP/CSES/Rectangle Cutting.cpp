#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=5010,MOD=1e9+7;
int dp[MAX][MAX],n,m;
int solve(int i,int j){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ret = 1e9;
    for(int c=1;c<=j/2;c++){
        ret = min(ret,1 + solve(i,c)+solve(i,j-c));
    }
    for(int r=1;r<=i/2;r++){
        ret = min(ret,1 + solve(r,j)+solve(i-r,j));
    }
    return dp[i][j]=ret;
}
int main() {
    memset(dp,-1,sizeof dp);
    scanf("%d %d",&n,&m);
    printf("%d\n" , solve( n , m));
	return 0;
}
