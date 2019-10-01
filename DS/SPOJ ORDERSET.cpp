#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ordered_set<int> S;
    int q;cin>>q;
    while(q--){
        int x;
        char ch;cin>>ch;
        if(ch=='I'){
            cin >> x;
            S.insert(x);
        }
        else if(ch=='C'){
            cin >> x;
            cout<<S.order_of_key(x)<<"\n";
        }
        else if(ch=='K'){
            cin >> x;x--;
            auto it = S.find_by_order(x);
            if(it==S.end()){
                cout<<"invalid\n";
                continue;
            }
            int res = * it;
            cout<<res<<"\n";
        }
        else if(ch=='D'){
            cin >> x;
            S.erase(x);
        }
    }
    return 0;
}
