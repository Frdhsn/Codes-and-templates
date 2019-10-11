#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
ll dp[MAX],w[MAX],val[MAX];
int main (){
    int N,W;cin >> N >> W;

    for(int i=0;i<N;i++){
        //int w,val;
        cin >> w[i] >> val[i];
        for(int j=MAX;j>=w[i];j--){
                if(j - w[i]>=0)
                dp[j] = max(dp[j],dp[j - w[i]] + val[i]);
        }
    }
    ll res=0;
    for(int i=0;i<=W;i++){
        //if(dp[i])cout<<i<<" "<<dp[i]<<endl;
        res = max(res,dp[i]);
    }
    cout<<res;
    return 0;
}
