#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
int n;
int dp[505][501*502/2];
ll solve(int idx,int sum){
    int rem = n*(n+1)/2 - sum;
    if(sum>rem)return 0;
    if(sum==rem)return 1;
    if(idx>n) return 0;
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    ll res = solve(idx+1 , sum) ;
    res%=MOD ;
    res+=solve(idx+1,sum+idx);
    res%=MOD;
    return dp[idx][sum] = res;
}
int main (){
    memset(dp,-1,sizeof dp);
    cin>>n;
    ll res = solve(1 , 0) * 500000004;
    res%=MOD;
    cout<<res<<endl;
    return 0;
}
