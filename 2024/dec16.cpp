#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <climits>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
int dij1[150][150], dij2[150][150], n, m, di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};
int sc[]={-1, 0, 1}, sum[]={1000,1,1000};
bool inmat(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

//set<pair<int, int>> st;
void dijkstra(int i, int j, int dir, int dij[][150]=dij1)
{
    set<pair<pair<int, int>, pair<int,int>>> st;
    st.insert({{0, dir}, {i, j}});
    dij[i][j]=0;
    while (!st.empty()){
        //cout<<i<<" - "<<j<<endl;
        i=st.begin()->second.first;
        j=st.begin()->second.second;
        dir=st.begin()->first.second;
        int tmp=st.begin()->first.first;
        st.erase(st.begin());
        if (tmp>dij[i][j])continue;
        for (int k=0; k<3; ++k){
            int kk=(dir+4+sc[k])%4;
            int pi=i+di[kk], pj=j+dj[kk];
            if (inmat(pi, pj)){
                if (v[pi][pj]!='#'){
                    if (dij[pi][pj]>dij[i][j]+sum[k]){
                        dij[pi][pj]=dij[i][j]+sum[k];
                        st.insert({{dij[pi][pj], kk}, {pi, pj}});
                    }
                }
            }
        }
    }
}
void reset(int dij[][150]){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            dij[i][j]=INT_MAX;
        }
    }
}
int smallestPath(int si, int sj, int ei, int ej)
{
    int mi=INT_MAX;
    reset(dij1);
    dijkstra(si, sj, 1);
    return dij1[ei][ej];
}
void read()
{
    string s;
    while (fin>>s){
        v.push_back(s);
    }
    n=v.size(), m=v[0].size();
}
void find(int &si, int &sj, int &ei, int &ej)
{
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (v[i][j]=='S'){
                si=i, sj=j;
            }
            if (v[i][j]=='E'){
                ei=i, ej=j;
            }
            //dij[i][j]=INT_MAX;
        }
    }
}
void p1(){
    read();
    int si, sj, ei, ej;
    find(si, sj, ei, ej);
    fout<<smallestPath(si, sj, ei, ej);
}
const int BIG_N=1024;
const int MAX=1<<30;

char tab[BIG_N][BIG_N], b[BIG_N][BIG_N] = {0};
int costs[BIG_N][BIG_N][4],sx,sy;

int turns[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
int turn_cost[4] = {0 , 1000, 2000, 1000};

void count_path(int x, int y, int turn, int cost){
    for (int i = 0; i < 4; i++) {
        if (i == 2) continue;

        int tx_x = turns[(turn + i) % 4][0];
        int tx_y = turns[(turn + i) % 4][1];

        if(tab[y + tx_y][x + tx_x] == '.'){
            int new_cost = cost + 1 + turn_cost[i];
            if (new_cost < costs[y + tx_y][x + tx_x][(turn + i) % 4]) {
                costs[y + tx_y][x + tx_x][(turn + i) % 4] = new_cost;
                count_path(x + tx_x, y + tx_y, (turn + i) % 4, new_cost);
            }
        }
    }
}

void resolve_path(int ex, int ey, int vec){
    b[ey][ex]=1;
    if(ex == sx && ey == sy) return;

    int ex2,ey2, min = MAX;

    for(int i=0; i<4; i++)
        if(costs[ey][ex][i] < min)
            min = costs[ey][ex][i];

    for(int i=0; i<4; i++) {
        if(costs[ey][ex][i] == min || (costs[ey][ex][i] == min+1000 && vec==i)){
            ex2=ex + turns[(i+2)%4][0];
            ey2=ey + turns[(i+2)%4][1];
            resolve_path(ex2,ey2,i);
        }
    }
}

int p2() 
{
    int ex,ey;

    while(fin>>tab[n]) n++;
    m=strlen(tab[0]);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++) costs[i][j][k]=MAX;
            if(tab[i][j] == 'S'){ sx=j; sy=i; tab[i][j] = '.'; }
            if(tab[i][j] == 'E'){ ex=j; ey=i; tab[i][j] = '.'; }
        }
    }

    count_path(sx,sy,2,0);
    resolve_path(ex,ey,0);

    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cnt+=b[i][j];

    fout<<cnt;

    return 0;
}
int main()
{
    //p1();
    p2();
}