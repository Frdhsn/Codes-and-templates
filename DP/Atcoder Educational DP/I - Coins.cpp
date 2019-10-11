#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N;
double H[3005];
double dp[3005][3005];
double solve(int idx,int head){
    if(idx>=N){
        int tail = N - head;
        if(head>tail)return 1;
        return 0;
    }
    if(dp[idx][head]!=-1)return dp[idx][head];
    double res = H[idx]*solve(idx+1,head+1) + (1-H[idx])*solve(idx+1,head);
    return dp[idx][head] = res;
}
int main ()
{
    for(int i=0;i<3005;i++)
    for(int j=0;j<3005;j++)dp[i][j]=-1;
    cin >>N;

    for(int i=0;i<N;i++){
            cin >> H[i];
    }
    cout<<fixed<<setprecision(20);
    cout<<solve(0,0);
    return 0;
}
