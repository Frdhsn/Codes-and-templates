#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
ll to_ll(string A){
    stringstream ss(A);
    ll x;
    ss>>x;
    return x;
}
char lo(char ch){
    if(ch>='a'&&ch<='z')return ch;
    if(ch>='A'&&ch<='Z')return ch-'A'+'a';
    return ch;
}
string f(string A){
    for(int i=0;i<A.size();i++)A[i]=lo(A[i]);
    return A;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("inok.txt","r",stdin);
    //freopen("outok.txt","w",stdout);
    int t;cin >> t;
    cin.ignore();

    for(int tc=1;tc<=t;tc++){
            if(tc>1)cout<<"\n";
            vector< pair<int ,pair<int,pair<int,pair<int,pii> > > > >  V;
            unordered_map<string,int>ID;

            string tournament;
            getline(cin,tournament);

            int teams;cin>>teams;
            int points[teams+10],wins[teams+10],score[teams+10],concede[teams+10],matchplayed[teams+10],draw[teams+10];
            memset(points,0,sizeof points);
            memset(wins,0,sizeof wins);
            memset(draw,0,sizeof draw);
            memset(score,0,sizeof score);
            memset(concede,0,sizeof concede);
            memset(matchplayed,0,sizeof matchplayed);
            cin.ignore();
            vector< pair<string,string> > names;
            for(int i=1;i<=teams;i++){
                string team;getline(cin,team);
                names.push_back({f(team),team});

                ID[team]=i;
            }
            sort(names.begin(),names.end());
            //cout<<"names: "<<endl;
            //for(auto x:names)cout<<x.second<<endl;
            int g;cin>>g;
            cin.ignore();
            for(int i=1;i<=g;i++){
                string S;getline(cin,S);
                string team1="",team2="";
                string s1="",s2="";
                int score_a = 0 , score_b = 0;
                int j=0;
                for(j=0;j<S.size();j++){
                    if(S[j]=='#')break;
                    team1.push_back(S[j]);
                }
                j++;
                for(;j<S.size();j++){
                    if(S[j]=='@')break;
                    s1.push_back(S[j]);
                }
                score_a = to_ll(s1);
                j++;
                for(;j<S.size();j++){
                    if(S[j]=='#')break;
                    s2.push_back(S[j]);
                }
                score_b = to_ll(s2);
                j++;
                for(;j<S.size();j++){
                    team2.push_back(S[j]);
                }
                int id1 = ID[team1] , id2 = ID[team2];
                score[id1]+=score_a;
                concede[id1]+=score_b;
                score[id2]+=score_b;
                concede[id2]+=score_a;
                matchplayed[id1]++;
                matchplayed[id2]++;
                if(score_a>score_b){wins[id1]++;points[id1]+=3;}
                else if(score_a<score_b){wins[id2]++;points[id2]+=3;}
                else {points[id1]++,points[id2]++;draw[id1]++,draw[id2]++;}
            }
            for(int i=1;i<=teams;i++){
                int i_ = ID[names[i-1].second];
                V.push_back({-points[i_], {-wins[i_],{ -(score[i_]-concede[i_]) ,{ -score[i_], { matchplayed[i_], i-1} } } } });
            }
//            cout<<"before sort: \n";
//            for(int i=0;i<V.size();i++){
//                cout<<-V[i].first<<" "<<V[i].second.second.second.second.second<<endl;
//            }
            sort(V.begin(),V.end());

//            cout<<"after sort: \n";
//            for(int i=0;i<V.size();i++){
//                cout<<-V[i].first<<" "<<V[i].second.second.second.second.second<<endl;
//            }
            cout<<tournament<<"\n";
            for(int i=1;i<=teams;i++){
                    int id = ID[ names[V[i-1].second.second.second.second.second].second];
                    //cout<<id<<endl;
cout<<i<<") "<<names[V[i-1].second.second.second.second.second].second<<" "<<points[id]<<"p, "<<matchplayed[id]<<"g ("<<wins[id]<<"-"<<draw[id]<<"-"<<matchplayed[id]-(wins[id]+draw[id])<<"), "<<score[id]-concede[id]<<"gd ("<<score[id]<<"-"<<concede[id]<<")\n";
            }
    }

    return 0;
}
/*
2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D
*/
