#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sc(x) scanf("%d",&x)
#define scL(x) scanf("%lld",&x)
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while(cin >> N && N){
        stack<int>stk;
        vector<int>discarded;
        for(int i=1;i<=N;i++){
                stk.push(N-i+1);
        }
        while(stk.size()>1){
            discarded.push_back(stk.top());
            stk.pop();

            int x = stk.top();
            stk.pop();
            stack<int>temp;
            while(!stk.empty()){temp.push(stk.top());stk.pop();}
            stk.push(x);
            while(!temp.empty()){stk.push(temp.top());temp.pop();}
        }
        cout<<"Discarded cards:";
        for(int i=0;i<discarded.size();i++){
            cout<<" "<<discarded[i];
            if(i<discarded.size()-1)cout<<",";
        }
        cout<<endl;
        cout<<"Remaining card: "<<stk.top()<<endl;
    }
    return 0;
}
/*
6
5 2 4 1 7 5
6
5 2 4 1 7 5
0
*/
