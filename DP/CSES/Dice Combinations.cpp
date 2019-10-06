#include<bits/stdc++.h>
using namespace std;
int main() {
	int N,MOD=1e9+7;cin >> N;
	int dp[N+10];
	memset(dp,0,sizeof dp);
	dp[1]=1;dp[0]=1;
	for(int i=2;i<=N;i++)
	{
	    for(int j=1;j<=6;j++)
	    {
	        int a=0;
	        if(i-j>=0){
	            a=dp[i-j]%MOD;
	            dp[i]+=a;
	            dp[i]%=MOD;
	        }
	    }
	}
	cout<<dp[N]%MOD<<endl;
}
