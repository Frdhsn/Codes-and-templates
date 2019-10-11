#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=3e3+10;
string A,B;
ll N,M;
ll dp[MAX][MAX];
int solve(int i,int j)
{
    if(i>=N||j>=M)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(A[i]==B[j]){
        ans =  1+solve(i+1,j+1);
    }
    else{
        ans = max(solve(i+1,j),solve(i,j+1));
    }
    return dp[i][j]=ans;
}
void path(int i,int j)
{
    if(i>=N||j>=M)return;
    if(A[i]==B[j]){
        cout<<A[i];
        path(i+1,j+1);
    }
    else{
        if(solve(i+1,j)==dp[i][j]){
            path(i+1,j);
        }
        else if(solve(i,j+1)==dp[i][j]){
            path(i,j+1);
        }
    }
}
int main ()
{
    memset(dp,-1,sizeof dp);
    cin >> A >> B;
    N = A.size();
    M = B.size();
    solve(0,0);
    path(0,0);
    return 0;
}



