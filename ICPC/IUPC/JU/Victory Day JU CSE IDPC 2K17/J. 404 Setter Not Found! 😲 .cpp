/*
  Idea: DSU
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 505;
int ID[MAX][MAX],A[MAX][MAX],M[MAX][MAX],par[MAX*MAX],res[MAX*MAX];
int Dx[] = {1,0,-1,0,0};
int Dy[] = {0,1,0,-1,0};
int find_par(int x){
    if(x==par[x])return x;
    return par[x] = find_par(par[x]);
}
void Union(int x,int y){
    int parx = find_par(x);
    int pary = find_par(y);
    if(parx==pary)return;
    par[pary] = parx;
}
void init(int n){
    for(int i=1;i<=n;i++)par[i]=i;
}
int cellmapping(int i,int j,int r,int c){
    return (i-1)*c + j;
}
bool valid(int i,int j,int n,int m){
    return i>=1&&i<=n&&j>=1&&j<=m;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        memset(res,0,sizeof res);
        int n,m;cin>>n>>m;
        init(n*m + 10);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> ID[i][j];
                M[i][j] = cellmapping(i,j,n,m);
                par[M[i][j]]=M[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cin >> A[i][j];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    pair<int,int> X={i,j};
                    int mn = 1e9;
                    for(int k=0;k<5;k++){
                        int xx = Dx[k] + i;
                        int yy = Dy[k] + j;
                        if(valid(xx,yy,n,m)==0)continue;

                        if(ID[xx][yy]<mn){
                            mn = ID[xx][yy];
                            X = {xx,yy};
                        }
                    }
                    int cell_id = M[X.first][X.second];
                    Union(cell_id,M[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int id = M[i][j];
                int boss = find_par(id);
                res[boss]+=A[i][j];
            }
        }
        int mx = -1e9;
        pair<int,int> Y={0 , 0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(res[M[i][j]]>=mx){
                    mx = res[M[i][j]];
                    Y = {i,j};
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<Y.first-1<<" "<<Y.second-1<<" "<<mx<<"\n";
    }
    return 0;
}
/*
2
2 2
1 2
3 4
1 2
3 4

3 3
1 2 5
3 4 6
3 1 2
1 2 5
3 4 6
3 1 2
*/
