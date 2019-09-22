// source: https://codeforces.com/blog/entry/14516
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<ll,ll>dp;
const int MOD=1e9+7;

ll moduloM(ll x,ll y,ll m)
{
	x%=m,y%=m;
	x = x * y ;
	x%=m;
	return x;
}
ll moduloP(ll x,ll y,ll m)
{
	x%=m,y%=m;
	x = x + y ;
	x%=m;
	return x;
}
ll f(int n){
	if(dp[n])return dp[n];
	ll k = n/2;
	if(k*2==n){
		ll a = f(k);
		a = moduloM(a,a,MOD);

		ll b = f(k-1);
		b = moduloM(b,b,MOD);
		return dp[n] = moduloP(a,b,MOD);
	}
	else{
		ll a = f(k-1) , b = f(k) , c = f(k+1);
		ll x = moduloM(a,b,MOD);
		ll y = moduloM(b,c,MOD);
		return dp[n] = moduloP(x,y,MOD);
	}
}
int main() {
	dp[0]=1 , dp[1]=1;
	ll n;cin >> n;
	if(n==0)cout<<0<<endl;
	else cout<<f(n-1)<<endl;
	return 0;
}

