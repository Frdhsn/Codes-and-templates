#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
ll dp[MAX];
int main (){
    int N,W;cin >> N >> W;
    memset(dp,63,sizeof dp);
    dp[0]=0;
    for(int i=0;i<N;i++){
        int w,val;
        cin >> w >> val;
        for(int j=MAX;j>=0;j--){
            if(j-val>=0)
                dp[j]=min(dp[j],dp[j-val]+w);
        }

    }
    int res=0;
    for(int i=0;i<MAX;i++){
        if(dp[i]<=W) res = max(res,i);
    }
    cout<<res<<endl;
    return 0;
}
