#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
int dij[1001][1001], n, m, di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};
int sc[]={-1, 0, 1}, sum[]={1001,1,1001};
bool inmat(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}
void dijkstra(int i, int j, int dir)
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
void reset(){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            dij[i][j]=INT_MAX;
        }
    }
}
int smallestPath(int si, int sj, int ei, int ej)
{
    int mi=INT_MAX;
    dijkstra(si, sj, 1);
    return dij[ei][ej];
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
            dij[i][j]=INT_MAX;
        }
    }
}
void p1(){
    read();
    int si, sj, ei, ej;
    find(si, sj, ei, ej);
    fout<<smallestPath(si, sj, ei, ej);
}
set<pair<int,int>>sp, tmp;
int ei, ej, sm;
void backtrack(int i, int j, int count=0)
{
    if (i==ei && j==ej && sm==count){
        cout<<"here";
        for (auto it:tmp){
            sp.insert(it);
        }
        return;
    }
    if (ei==i && ej==j)return;
    if (sm<count)return;
    
    //cod de backtracking
    for (int kk=0; kk<3; ++kk){
        int k=(4+sc[kk])%4;
        int pi=i+di[k], pj=j+dj[k];
        if (inmat(pi, pj)){
            if (v[pi][pj]!='#' && !tmp.count({pi, pj})){
                tmp.insert({pi, pj});
                backtrack(pi, pj, count+sum[kk]);
                tmp.erase({pi, pj});
            }
        }
    }
}
void p2(){
    read();
    int si, sj;
    find(si, sj, ei, ej);
    sm=smallestPath(si, sj, ei, ej);
    cout<<sm<<endl;
    //reset();
    backtrack(ei, ej);
    fout<<sp.size();
}
int main()
{
    //p1();
    p2();
}