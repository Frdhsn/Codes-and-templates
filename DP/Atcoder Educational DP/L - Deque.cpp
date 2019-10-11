//
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=3e3 + 10;
ll N,A[MAX];
ll dp[MAX][MAX];
ll solve(int l,int r,int turn) // turn 1 == taro
{
    if(l==r){
            if(turn)return A[l];
            return 0;
    }
    if(l>r||r<l)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    ll res=0,a=0,b=0;
    if(turn)a=A[l];
    if(turn)b=A[r];
    /*if(A[l]>A[r])
    {
        res = a+solve(l+1,r,turn^1);
    }
    else if(A[l]<A[r])
    {
        res = b+solve(l,r-1,turn^1);
    }
    else
    {*/
        res = a+solve(l+1,r,turn^1);
        if(turn)
        res = max(res,b+solve(l,r-1,turn^1));
        else res = min(res,b+solve(l,r-1,turn^1));
    //}
    return dp[l][r]=res;
}
int main ()
{
    memset(dp,-1,sizeof dp);
    ll s=0;
    cin >> N;
    for(int i=0;i<N;i++){
            cin >> A[i];s+=A[i];
    }
    ll x = solve(0,N-1,1);
    ll y = s-x;
    //cout<<x<<endl;
    //cout<<y<<endl;
    cout<<x-y<<endl;
    return 0;
}

