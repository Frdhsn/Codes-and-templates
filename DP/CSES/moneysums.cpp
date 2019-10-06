#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=105;
int A[MAX],dp[MAX][MAX*1005];
// dp[i][j] means 0..i elements have a subset whose sum is j
int main (){
    int N;cin>>N;
    ll sum=0;
    for(int i=0;i<N;i++){
            cin >> A[i];
            sum+=A[i];
    }
    for(int i=0;i<=N;i++)dp[i][0]=1;
    
    for(int i=1;i<=N;i++){
            dp[i][A[i-1]]=1;
            for(int j=1;j<=sum;j++){
                if(dp[i-1][j]){
                    dp[i][j]=1;
                    dp[i][j+A[i-1]]=1;
                }
            }
    }
    vector<int>res;
    for(int i=1;i<=sum;i++)if(dp[N][i])res.push_back(i);
    cout<<res.size()<<endl;
    for(int x:res)cout<<x<<" ";
    cout<<endl;
    return 0;
}
