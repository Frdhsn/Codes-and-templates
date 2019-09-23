#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
const int MAX = 1e6 + 10;
int id,primes[78500];
bool isprime[MAX];
void sieve()
{
    primes[0]=2;
    for(int i=4;i<MAX;i+=2)isprime[i]=1;
    for(int i=3;i<MAX;i+=2){
        if(isprime[i]==0){
            primes[++id]=i;
            if(i+i<MAX)
            for(int j=i+i;j<MAX;j+=i)
                isprime[j]=1;
        }
    }
}
vector<pii> factfactorise(int n)
{
    vector<pii> F;
    for(int i=0;i<id&&primes[i]<=n;i++){
        ll curr = primes[i];
            ll num = n ;
            ll cnt = 0 ;
            while( num / curr){
                cnt += num/curr;
                curr*=primes[i];
            }
            if(cnt)
            F.push_back({primes[i] , cnt});
        
    }
    return F;
}
int main ()
{
    sieve();
    int n;
    while(cin >> n && n){
            vector<pii> F = factfactorise(n);
            for(int i=0;i<F.size();i++){
                cout<<F[i].first<<" "<<F[i].second<<endl;
            }
    }
    return 0;
}
