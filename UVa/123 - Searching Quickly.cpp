#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char lo(char ch){
    if(ch>='a'&&ch<='z')return ch;
    if(ch>='A'&&ch<='Z')return ch-'A'+'a';
    return ch;
}
char up(char ch){
    if(ch>='A'&&ch<='Z')return ch;
    if(ch>='a'&&ch<='z')return ch-'a'+'A';
    return ch;
}
string low(string A){
    for(int i=0;i<A.size();i++)A[i]=lo(A[i]);
    return A;
}
string upp(string A){
    for(int i=0;i<A.size();i++)A[i]=up(A[i]);
    return A;
}
vector<string>f(string S){
    vector<string>V;
    string A;
    stringstream ss(S);
    while(ss>>A){
        V.push_back(A);
    }
    return V;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector< pair< pair<string,int> ,string > > ans;

    string S;
    unordered_map<string,bool>avoid;
    while(cin>>S){
            if(S=="::")break;
            avoid[S]=1;
    }
    int n=0;
    while(getline(cin,S)){
        S = low(S);
        vector< pair< pair<int,int> , string > > haha;
        for(int i=0;i<S.size();i++){
            if(S[i]==' ')continue;
            string word = "";
            int j = i;
            while(j<S.size()){
                if(S[j]==' ')break;
                word.push_back(S[j]);
                j++;
            }
            if(avoid[word]==0)haha.push_back({{i,j-1},word});
            i=j;
        }
        //cout<<"S = "<<S<<endl;
        for(int i=0;i<haha.size();i++){
            int f = haha[i].first.first;
            int s = haha[i].first.second;
            //cout<<f<<" "<<s<<endl;
            string temp=S;

            for(int j=0;j<S.size();j++){
                if(j>=f&&j<=s){
                        temp[j]=up(S[j]);
                }
                else temp[j]=S[j];
            }
            //cout<<haha[i].second<<" "<<temp<<endl;
            ans.push_back({{haha[i].second , n},temp});
        }
        n++;
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)cout<<x.second<<endl;
    return 0;
}
/*
*/

