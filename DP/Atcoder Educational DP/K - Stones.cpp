#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5 + 10,MOD=1e9 + 7;
int N,K,A[105],mn=1e9;
int dp[MAX][2];
int f(int rem,int turn)
{
    if(rem<mn&&turn==1)return 0;
    if(rem<mn&&turn==0)return 1;
    if(dp[rem][turn]!=-1)return dp[rem][turn];
    for(int i=0;i<N;i++)
    {
        if(rem-A[i]>=0)
        if(f(rem-A[i],turn^1)==turn){
            return dp[rem][turn] = turn;
        }
    }
    return dp[rem][turn] = turn^1;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof dp);
    cin >> N >> K;
    for(int i=0;i<N;i++){cin>>A[i];mn = min(mn,A[i]);}
    if(f(K,0)==0){
        cout<<"First\n";
    }
    else cout<<"Second\n";
    //main();
    return 0;
}
