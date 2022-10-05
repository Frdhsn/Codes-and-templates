// link: https://atcoder.jp/contests/abc157/tasks/abc157_e
//Author: thehalfbloodprince
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define    flash           ios_base::sync_with_stdio(false);cin.tie(0);
#define    ff              first
#define    ss              second
#define    pb              push_back
#define    m_p             make_pair
#define    GCD(a,b)        __gcd(a,b)
#define    LCM(a,b)        (a*b)/GCD(a,b)
#define    MEM(a,b)        memset(a,b,sizeof a)
#define    PCs(a)          printf("Case %d: ",a)
#define    WRITE(a)        freopen(a,"w",stdout)
#define    READ(a)         freopen(a,"r",stdin)
#define    LB(a,x)         (lower_bound(a.begin(),a.end(),x) - a.begin())
#define    UB(a,x)         (upper_bound(a.begin(),a.end(),x) - a.begin())
#define    PI              2.0*acos(0.0)
#define    MOD1            1000000007 // prime
#define    MOD2            1000000009 // prime
#define    MOD3            1000000021 // prime
#define    Base1           10000019
#define    Base2           10000079
#define    Base3           10000103
#define    endl             '\n'
//#define    MAX             1000007
typedef    pair<int, int> pii;
typedef    pair<int, pii> ppi;
typedef    pair<pii, int> pip;
typedef    long long int ll;
typedef    unsigned long long int ull;
typedef    pair<ll, ll> pll;
typedef    vector<int> VI;
typedef    vector<pii> Vii;
typedef    vector<VI> VVI;// 2D
//typedef    priority_queue<int> PQ;// MaxHeap
typedef    priority_queue<int, VI, greater<int> > PQ; // MinHeap
/*
inline int stringToInt(string a)
{
    int num;
    stringstream aw(a);
    aw>>num;
    return num;
}*/

//inline ll stringToLL(string a)
//{
//    ll num;
//    stringstream aw(a);
//    aw>>num;
//    return num;
//}
/*
inline int iPOW(int a,int e)
{
    int num=1;
    while(e)
    {
        if(e%2)
        {
            num=num * a;
        }
        e/=2;
        a=a * a;
    }
    return num;
}
inline ll LPOW(ll a,ll e)
{
    ll num=1;
    while(e)
    {
        if(e%2)
        {
            num=num * a;
        }
        e/=2;
        a=a * a;
    }
    return num;
}*/

//inline ll BigMod(ll a,ll e,ll mod)
//{
//    ll num=1;
//    while(e)
//    {
//        if(e%2)
//        {
//            a%=mod;
//            num%=mod;
//            num=num * a;
//            num%=mod;
//        }
//        e/=2;
//        a%=mod;
//        a=a * a;
//        a%=mod;
//    }
//    return num%mod;
//}
/*inline ll modInverse(ll A,ll P)
{
    return BigMod(A,P-2,P);
}
ll fac[MAX];
inline void factorial(int n,int mod)
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=MAX;i++) fac[i]=( (fac[i-1]%mod)*i)%mod;
}
inline int nCr(int n,int r,int mod) // ncr with mod
{
    return ((fac[n] * modInverse(fac[r],mod)%mod)%mod * (modInverse(fac[n-r],mod)%mod) ) %mod;
}
*/
/*
bool isprime[MAX+1000];
int Primes[MAX],id;// for <=10^6
void sieve()
{
    Primes[0]=2;
    id++;
    for(int i=4;i<=MAX+100;i+=2) isprime[i]=true;// is not a prime
    for(int i=3;i<=MAX+100;i+=2)
    {
        if(isprime[i]==false)
        {
            Primes[id++]=i;
            if(i+i<=MAX)
            for(int j=i+i;j<=100+MAX;j+=i)
                isprime[j]=true;
        }
    }
}*/
//int Dx[] ={-1,0, 0,1};
//int Dy[] ={ 0,1,-1,0};
//int Dx8[]={-1,-1,-1,0,1,1, 1, 0};
//int Dy8[]={-1, 0, 1,1,1,0,-1,-1};
//int Kx[] ={2,1,-1,-2,-2,-1, 1, 2};
//int Ky[] ={1,2, 2, 1,-1,-2,-2,-1};

// code starts from here
const int MAX=3007,MOD=1e9+7,MOD4=998244353;
//multiset
//template<typename T>
//using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//set
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ordered_set<int> table[27];

void update(int pos,char ch,string &s){
    if(s[pos-1] == ch)return;
    table[s[pos-1]-'a'].erase(table[s[pos-1]-'a'].lower_bound(pos));
    s[pos-1]=ch;
    table[s[pos-1]-'a'].insert(pos);
}
int query(int l,int r){
    int res=0;
    for(int i=0;i<26;i++){
        int r_cnt =0,l_cnt =0;
        if(table[i].size()>1){

            r_cnt = table[i].order_of_key(r);
            if(*table[i].find_by_order(r_cnt) != r)
                r_cnt--;
            l_cnt = table[i].order_of_key(l-1);
            if(*table[i].find_by_order(l_cnt) != l-1)
                l_cnt--;
        }
        r_cnt = max(0,r_cnt);
        l_cnt = max(0,l_cnt);
        if(r_cnt-l_cnt>0)res++;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    string s;cin>>s;
    for(int i=0;i<26;i++)
        table[i].insert(0);
    for(int i=0;i<n;i++){
        table[s[i]-'a'].insert(i+1);
    }
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type == 1){
            int pos;char ch;cin>>pos>>ch;
            update(pos,ch,s);
        }
        else{

            int l,r;cin>>l>>r;
            cout<<query(l,r)<<endl;
        }
    }
}
int main ()
{
    flash;

    int t = 1;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
