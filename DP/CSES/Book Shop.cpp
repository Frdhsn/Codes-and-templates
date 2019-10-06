#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+5,MOD=1e9+7;
int dp[MAX] , n , P , price[MAX] , page[MAX];
int main() {
    //memset(dp,-1,sizeof dp);
    cin>>n>>P;
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>page[i];
	//int res = 0;
 
    dp[0] = 0;
 
    for(int i=0;i<n;i++){
        for(int j = P ; j>=price[i] ; j--){
            if( j - price[i] >=0 ) dp[j] = max( dp[j] , page[i] + dp[j- price[i]]);
        }
    }
    int res=0;
    for(int i=0;i<=P;i++)res=max(res,dp[i]);
	cout<<res<<endl;
	
